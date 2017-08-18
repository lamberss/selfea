add_executable(test_selfea_math test_matrix.cpp)
target_link_libraries(test_selfea_math selfea_math ${GTEST_BOTH_LIBRARIES} pthread)
add_test(selfea_test_math test_selfea_math)
