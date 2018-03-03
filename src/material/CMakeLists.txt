add_library(selfea_material isotropic.cpp material.cpp)
if(CLANG_TIDY_EXE)
    set_target_properties(selfea_material PROPERTIES
                          CXX_CLANG_TIDY "${DO_CLANG_TIDY}")
endif()
