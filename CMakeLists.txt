cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    MaxTrees
    VERSION 0.1.0
    DESCRIPTION "Finding the maximum number of trees from a view angle"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    MaxTrees_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    MaxTrees_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(MaxTrees_lib PUBLIC cxx_std_14)

# ---- Declare executable ----

add_executable(MaxTrees_exe source/main.cpp)
add_executable(MaxTrees::exe ALIAS MaxTrees_exe)

set_property(TARGET MaxTrees_exe PROPERTY OUTPUT_NAME MaxTrees)

target_compile_features(MaxTrees_exe PRIVATE cxx_std_14)

target_link_libraries(MaxTrees_exe PRIVATE MaxTrees_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT MaxTrees_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of MaxTrees"
  )
endif()

include(cmake/dev-mode.cmake)
