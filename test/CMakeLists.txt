# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(MaxTreesTests LANGUAGES CXX)

# ---- Tests ----

add_executable(MaxTrees_test source/MaxTrees_test.cpp)
target_link_libraries(MaxTrees_test PRIVATE MaxTrees_lib)
target_compile_features(MaxTrees_test PRIVATE cxx_std_14)

add_test(NAME MaxTrees_test COMMAND MaxTrees_test)

# ---- End-of-file commands ----

add_folders(test)
