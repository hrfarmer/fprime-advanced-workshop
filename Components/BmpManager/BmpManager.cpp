// ======================================================================
// \title  BmpManager.cpp
// \author pi
// \brief  cpp file for BmpManager component implementation class
// ======================================================================

#include "Components/BmpManager/BmpManager.hpp"

namespace DataProducts {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

BmpManager ::BmpManager(const char *const compName)
    : BmpManagerComponentBase(compName) {}

BmpManager ::~BmpManager() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void BmpManager ::Bmp280DataIn_handler(FwIndexType portNum,
                                       const Bmp280::Bmp280Data &data) {
  if (!this->m_containerValid) {
    const FwSizeType containerSize = RECORD_COUNT * (BmpSample::SERIALIZED_SIZE + sizeof(FwDpIdType)) * 2;

    Fw::Success status = this->dpGet_Bmp280DataContainer(containerSize, this->m_container);
    if (status != Fw::Success::SUCCESS) {
      this->log_WARNING_HI_Bmp280ProducerMemoryFailure(containerSize);
    } else {
      this->m_containerValid = true;
      this->m_container.setTimeTag(this->getTime());
      this->log_WARNING_HI_Bmp280ProducerMemoryFailure_ThrottleClear();
    }
  }

  if (this->m_containerValid) {
    Fw::Time currentFwTime = this->getTime();
    Fw::TimeValue currentTime = Fw::TimeValue(currentFwTime.getTimeBase(), currentFwTime.getContext(),
                                              currentFwTime.getSeconds(), currentFwTime.getUSeconds());
    
    BmpSample bmpSampleRecord;
    bmpSampleRecord.set_timestamp(currentTime);
    bmpSampleRecord.set_altitude(data.get_altitude());
    bmpSampleRecord.set_pressure(data.get_pressure());
    bmpSampleRecord.set_temperature(data.get_temperature());

    Fw::SerializeStatus status = this->m_container.serializeRecord_Bmp280ProductRecord(bmpSampleRecord);
    FW_ASSERT(status == Fw::SerializeStatus::FW_SERIALIZE_OK);
    this->m_count++;

    if (this->m_count == RECORD_COUNT) {
      this->dpSend(this->m_container);
      this->m_count = 0;
      this->m_containerValid = false;
    }

  }
}

void BmpManager ::run_handler(FwIndexType portNum, U32 context) {
  // TODO
}

} // namespace DataProducts
