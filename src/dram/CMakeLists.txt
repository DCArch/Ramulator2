add_library(ramulator-dram OBJECT)

target_sources(
  ramulator-dram PRIVATE
  dram.h  node.h  spec.h  lambdas.h  
  
  lambdas/preq.h  lambdas/rowhit.h  lambdas/rowopen.h lambdas/action.h lambdas/power.h

  impl/DDR3.cpp
  impl/DDR4.cpp
  impl/DDR4-VRR.cpp
  impl/DDR4-RVRR.cpp
  impl/DDR5.cpp
  impl/DDR5-VRR.cpp
  impl/DDR5-RVRR.cpp
  impl/LPDDR5.cpp
  impl/HBM.cpp
  impl/HBM2.cpp
  impl/HBM3.cpp
)

target_compile_options(ramulator-dram PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-dram
)
