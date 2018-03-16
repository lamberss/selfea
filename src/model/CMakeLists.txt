add_library(selfea_model model.cpp node.cpp)
if(CLANG_TIDY_EXE)
    set_target_properties(selfea_model PROPERTIES
                          CXX_CLANG_TIDY "${DO_CLANG_TIDY}")
endif()
