add_library(ramulator-memorysystem OBJECT)

target_sources(
  ramulator-memorysystem PRIVATE
  bh_memory_system.h
  memory_system.h

  impl/bh_DRAM_system.cpp
  impl/dummy_memory_system.cpp
  impl/generic_DRAM_system.cpp
)

target_compile_options(ramulator-memorysystem PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-memorysystem
)
