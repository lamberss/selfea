add_executable(test_selfea_material test_isotropic.cpp test_material.cpp)
target_link_libraries(test_selfea_material selfea_material ${GTEST_BOTH_LIBRARIES} pthread)
add_test(selfea_test_material test_selfea_material)
