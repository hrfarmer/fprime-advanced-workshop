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
  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  //! Construct BmpManager object
  BmpManager(const char *const compName //!< The component name
  );

  //! Destroy BmpManager object
  ~BmpManager();
};

} // namespace DataProducts

#endif
