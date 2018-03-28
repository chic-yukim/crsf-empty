# Author: Younguk Kim (bluekyu)

cmake_minimum_required(VERSION 3.9)
project(CRSF-Projects)

# === configure ====================================================================================
set(CRSF_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/crsf")

if(NOT EXISTS ${CRSF_SDK_DIR})
    message(FATAL_ERROR
        "'crsf' directory does NOT exist!\n"
        "You can download from http://crseed.org"
    )
endif()

# list projects
add_subdirectory("empty-project")
# ==================================================================================================
