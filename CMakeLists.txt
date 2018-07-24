cmake_minimum_required(VERSION 3.10)
project(CRSF-Projects LANGUAGES NONE)

# === configure ====================================================================================
set(CRSF_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/crsf")

if(NOT EXISTS ${CRSF_SDK_DIR})
    message(FATAL_ERROR "'crsf' directory does NOT exist!\nYou can download from http://crseed.org")
endif()

# uncomment this to add examples
#add_subdirectory("crsf/examples")

# list modules
add_subdirectory("empty_module")

# list projects
add_subdirectory("empty_project")
# ==================================================================================================
