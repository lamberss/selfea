cmake_minimum_required(VERSION 3.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the type of build, options are: Debug Release
 RelWithDebInfo MinSizeRel."
    FORCE)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(selfea C CXX)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic")
enable_testing()

if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    include(CodeCoverage)
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${CMAKE_C_FLAGS_COVERAGE}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_COVERAGE}")
    setup_target_for_coverage(selfea_coverage "make test" coverage)
endif()

include(CheckTypeSize)
CHECK_TYPE_SIZE(int           SELFEA_SIZEOF_INT)
CHECK_TYPE_SIZE(long          SELFEA_SIZEOF_LONG)
CHECK_TYPE_SIZE(char          SELFEA_SIZEOF_CHAR)
CHECK_TYPE_SIZE(short         SELFEA_SIZEOF_SHORT)
CHECK_TYPE_SIZE("long long"   SELFEA_SIZEOF_LONG_LONG)
CHECK_TYPE_SIZE(float         SELFEA_SIZEOF_FLOAT)
CHECK_TYPE_SIZE(double        SELFEA_SIZEOF_DOUBLE)
check_type_size("long double" SELFEA_SIZEOF_LONG_DOUBLE)


string(TIMESTAMP BUILD_DATE "%Y-%m-%d" UTC)
string(TIMESTAMP BUILD_TIME "%H:%M:%SZ" UTC)
configure_file("${PROJECT_SOURCE_DIR}/include/selfea/config.hpp.in"
  "${PROJECT_BINARY_DIR}/include/selfea/config.hpp")
include_directories("${PROJECT_BINARY_DIR}/include"
  "${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
