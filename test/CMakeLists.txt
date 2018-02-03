#find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
message(STATUS "GTEST_INCLUDE_DIR: ${GTEST_INCLUDE_DIR}")

add_subdirectory(material)
add_subdirectory(math)
