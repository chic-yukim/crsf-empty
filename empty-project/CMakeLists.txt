# Author: Younguk Kim (bluekyu)
# Date  : 2017-05-12

cmake_minimum_required(VERSION 3.6)

set(CRMODULE_ID "empty-project")
project(crmodule_${CRMODULE_ID})

# === configure ====================================================================================
set_property(GLOBAL PROPERTY USE_FOLDERS ON)    # Project Grouping

# find CRSF SDK
if(NOT CRSF_SDK_DIR)
    string(REPLACE "\\" "/" CRSF_SDK_DIR "$ENV{CRSF_SDK_DIR}")
    message("CRSF SDK: ${CRSF_SDK_DIR}")
endif()
list(APPEND CMAKE_MODULE_PATH "${CRSF_SDK_DIR}/cmake")

set(CRMODULE_INSTALL_DIR "${CRMODULE_ID}")

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# === project specific packages ===
include(FindPackages)
# ==================================================================================================

# === target =======================================================================================
include("${PROJECT_SOURCE_DIR}/files.cmake")
add_library(${PROJECT_NAME} MODULE ${module_sources} ${module_headers})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MP /wd4251)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif()

target_compile_definitions(${PROJECT_NAME}
    PRIVATE CRMODULE_ID_STRING="${CRMODULE_ID}"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE $<$<NOT:$<BOOL:Boost_USE_STATIC_LIBS>>:Boost::dynamic_linking>
    CRSeedLib spdlog::spdlog
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "MyProject"
    DEBUG_POSTFIX ${CRSeedLib_DEBUG_POSTFIX}
    RELWITHDEBINFO_POSTFIX ${CRSeedLib_RELWITHDEBINFO_POSTFIX}
    VERSION ${PROJECT_VERSION}
)

# configure local debugging for MSVC
if((MSVC) AND (WIN32))
    set(${PROJECT_NAME}_JUNCTION_DIRS "resources" "config")
    configure_build_directory("application" "${${PROJECT_NAME}_JUNCTION_DIRS}")
endif()
# ==================================================================================================

# === install ======================================================================================
install(TARGETS ${PROJECT_NAME} DESTINATION ${CRMODULE_ID})

# install module files.
install(FILES "${PROJECT_SOURCE_DIR}/config.json" DESTINATION ${CRMODULE_ID} CONFIGURATIONS Release)
if(EXISTS "${PROJECT_SOURCE_DIR}/resources")
    install(DIRECTORY "${PROJECT_SOURCE_DIR}/resources" DESTINATION ${CRMODULE_ID} CONFIGURATIONS Release)
endif()

# install application files
if(EXISTS "${PROJECT_SOURCE_DIR}/config")
    install(DIRECTORY "${PROJECT_SOURCE_DIR}/config" DESTINATION ${CRMODULE_ID})
endif()
# ==================================================================================================
