add_library(ramulator-addrmapper OBJECT)

target_sources(
  ramulator-addrmapper PRIVATE
  addr_mapper.h 

  impl/linear_mappers.cpp
  impl/rit.cpp
  impl/rit.h
)

target_compile_options(ramulator-addrmapper PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-addrmapper
)
