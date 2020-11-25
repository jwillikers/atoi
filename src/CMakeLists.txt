include(GenerateExportHeader)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS no)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(atoi)
add_library(atoi::atoi ALIAS atoi)
generate_export_header(atoi EXPORT_FILE_NAME
                       ${ATOI_GENERATED_INCLUDEDIR}/atoi/export.h)
target_include_directories(
  atoi
  INTERFACE $<BUILD_INTERFACE:${ATOI_GENERATED_INCLUDEDIR}>
  PRIVATE ${ATOI_GENERATED_INCLUDEDIR})
target_sources(atoi PRIVATE atoi.c)
target_compile_options(
  atoi
  PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Werror>
          $<$<CXX_COMPILER_ID:Clang>:-Weverything>
          $<$<CXX_COMPILER_ID:GNU>:-Werror>
          $<$<CXX_COMPILER_ID:GNU>:-Wall>
          $<$<CXX_COMPILER_ID:MSVC>:/WX>
          $<$<CXX_COMPILER_ID:MSVC>:/W3>)

if(TEST_ATOI OR CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  add_executable(atoi-test)
  target_sources(atoi-test PRIVATE atoi.test.cpp)
  target_link_libraries(atoi-test PRIVATE atoi::atoi boost::ut)
  target_compile_options(
    atoi-test
    PRIVATE $<$<CXX_COMPILER_ID:Clang>:-Werror>
            $<$<CXX_COMPILER_ID:Clang>:-Weverything>
            $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat>
            $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat-pedantic>
            $<$<CXX_COMPILER_ID:Clang>:-Wno-c99-extensions>
            $<$<CXX_COMPILER_ID:Clang>:-Wno-comma>
            $<$<CXX_COMPILER_ID:Clang>:-Wno-newline-eof>
            $<$<CXX_COMPILER_ID:GNU>:-Werror>
            $<$<CXX_COMPILER_ID:GNU>:-Wall>
            $<$<CXX_COMPILER_ID:MSVC>:/WX>
            $<$<CXX_COMPILER_ID:MSVC>:/W3>)
  add_test(NAME atoi-test COMMAND atoi-test)
  set_tests_properties(atoi-test PROPERTIES LABELS "atoi")
endif()
