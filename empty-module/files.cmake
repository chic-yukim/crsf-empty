set(header_include
    "${PROJECT_SOURCE_DIR}/include/empty_module/empty_module.h"
)

# grouping
source_group("empty_module" FILES ${header_include})

set(module_headers
    ${header_include}
)


set(source_src
    "${PROJECT_SOURCE_DIR}/src/empty_module.cpp"
)

# grouping
source_group("src" FILES ${source_src})

set(module_sources
    ${source_src}
)
