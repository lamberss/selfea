add_library(selfea_math matrix.cpp)
if(CLANG_TIDY_EXE)
    set_target_properties(selfea_math PROPERTIES
                          CXX_CLANG_TIDY "${DO_CLANG_TIDY}")
endif()
