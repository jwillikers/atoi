add_library(atoi)
add_library(atoi::atoi ALIAS atoi)
target_sources(atoi PRIVATE atoi.c)
target_compile_options(atoi PRIVATE
                       $<$<CXX_COMPILER_ID:Clang>:-Werror>
                       $<$<CXX_COMPILER_ID:Clang>:-Weverything>
                       $<$<CXX_COMPILER_ID:GNU>:-Werror>
                       $<$<CXX_COMPILER_ID:GNU>:-Wall>
                       $<$<CXX_COMPILER_ID:MSVC>:/WX>
                       $<$<CXX_COMPILER_ID:MSVC>:/W3>)

if(TEST_ATOI OR CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
	add_executable(atoi-test)
	target_sources(atoi-test PRIVATE atoi.test.cpp)
	target_link_libraries(atoi-test PRIVATE atoi::atoi boost::ut)
	target_compile_options(atoi-test INTERFACE
	                       $<$<CXX_COMPILER_ID:Clang>:-Werror>
	                       $<$<CXX_COMPILER_ID:Clang>:-Weverything>
	                       $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat>
	                       $<$<CXX_COMPILER_ID:Clang>:-Wno-c++98-compat-pedantic>
	                       $<$<CXX_COMPILER_ID:Clang>:-Wno-c99-extensions>
	                       $<$<CXX_COMPILER_ID:GNU>:-Werror>
	                       $<$<CXX_COMPILER_ID:GNU>:-Wall>
	                       $<$<CXX_COMPILER_ID:MSVC>:/WX>
	                       $<$<CXX_COMPILER_ID:MSVC>:/W3>)
	add_test(NAME atoi-test COMMAND atoi-test)
	set_tests_properties(atoi-test PROPERTIES LABELS "atoi")
endif()