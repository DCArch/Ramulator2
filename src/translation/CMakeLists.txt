add_library(ramulator-translation OBJECT)

target_sources(
  ramulator-translation PRIVATE
  translation.h

  impl/no_translation.cpp
  impl/random_translation.cpp
)

target_compile_options(ramulator-translation PRIVATE -fPIC -DFMT_HEADER_ONLY=1 -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0)

target_link_libraries(
  ramulator
  PRIVATE
  ramulator-translation
)
