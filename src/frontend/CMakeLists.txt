add_library(ramulator-frontend OBJECT)

target_sources(
  ramulator-frontend PRIVATE
  frontend.h

  impl/memory_trace/loadstore_trace.cpp
  impl/memory_trace/readwrite_trace.cpp

  impl/processor/simpleO3/simpleO3.cpp
  impl/processor/simpleO3/core.h      impl/processor/simpleO3/core.cpp
  impl/processor/simpleO3/llc.h       impl/processor/simpleO3/llc.cpp
  impl/processor/simpleO3/trace.h     impl/processor/simpleO3/trace.cpp

  impl/processor/bhO3/bhO3.h      impl/processor/bhO3/bhO3.cpp
  impl/processor/bhO3/bhcore.h    impl/processor/bhO3/bhcore.cpp
  impl/processor/bhO3/bhllc.h     impl/processor/bhO3/bhllc.cpp

  impl/external_wrapper/gem5_frontend.cpp
)

target_compile_options(ramulator-frontend PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-frontend
)
