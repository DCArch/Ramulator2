add_library(ramulator-base OBJECT)

target_sources(
  ramulator-base PRIVATE
  base.h      
  factory.h   factory.cpp
  type.h
  exception.h
  debug.h
  param.h 
  utils.h     utils.cpp
  config.h    config.cpp
  clocked.h
  stats.h     stats.cpp
  request.h   request.cpp
  serialization.h
)

target_compile_options(ramulator-base PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-base
)
