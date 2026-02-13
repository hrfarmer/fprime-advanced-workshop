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
  // TODO
}

void BmpManager ::run_handler(FwIndexType portNum, U32 context) {
  // TODO
}

} // namespace DataProducts
