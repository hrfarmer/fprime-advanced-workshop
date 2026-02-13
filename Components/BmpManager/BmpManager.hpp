// ======================================================================
// \title  BmpManager.hpp
// \author pi
// \brief  hpp file for BmpManager component implementation class
// ======================================================================

#ifndef DataProducts_BmpManager_HPP
#define DataProducts_BmpManager_HPP

#include "Components/BmpManager/BmpManagerComponentAc.hpp"

namespace DataProducts {

class BmpManager final : public BmpManagerComponentBase {

public:
    constexpr static const FwSizeType RECORD_COUNT = 100;  //!< Number of records of each type in the data product
  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  //! Construct BmpManager object
  BmpManager(const char *const compName //!< The component name
  );

  //! Destroy BmpManager object
  ~BmpManager();

private:
  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  //! Handler implementation for Bmp280DataIn
  void Bmp280DataIn_handler(FwIndexType portNum, //!< The port number
                            const Bmp280::Bmp280Data &data) override;

  //! Handler implementation for run
  void run_handler(FwIndexType portNum, //!< The port number
                   U32 context          //!< The call order
                   ) override;
  // Vars
  FwSizeType m_count;
  DpContainer m_container;
  bool m_containerValid;
};


} // namespace DataProducts

#endif
