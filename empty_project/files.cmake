set(source_src
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/main.hpp"
)

set(source_src_main_gui
    "${PROJECT_SOURCE_DIR}/src/main_gui/main_gui.cpp"
    "${PROJECT_SOURCE_DIR}/src/main_gui/main_gui.hpp"
)

# grouping
source_group("src" FILES ${source_src})
source_group("src\\main_gui" FILES ${source_src_main_gui})

set(module_sources
    ${source_src}
    ${source_src_main_gui}
)
