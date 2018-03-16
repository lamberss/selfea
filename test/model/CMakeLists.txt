add_executable(test_selfea_model test_model.cpp test_node.cpp)
target_link_libraries(test_selfea_model selfea_model ${GTEST_BOTH_LIBRARIES} pthread)
add_test(selfea_test_model test_selfea_model)
