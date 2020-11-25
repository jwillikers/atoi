include(FetchContent)

if(TEST_ATOI OR CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  FetchContent_Declare(
    ut
    GIT_REPOSITORY https://github.com/boost-ext/ut.git
    GIT_TAG v1.1.8)

  FetchContent_MakeAvailable(ut)
endif()
