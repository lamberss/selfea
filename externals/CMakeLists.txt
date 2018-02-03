add_subdirectory(googletest_1.8.0)
set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest_1.8.0/googletest/include PARENT_SCOPE)
set(GTEST_BOTH_LIBRARIES gtest gtest_main PARENT_SCOPE)
set(GMOCK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest_1.8.0/googlemock/include PARENT_SCOPE)
