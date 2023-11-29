find_package(Qt5 REQUIRED COMPONENTS Widgets Sql)

set(SOURCES
    scenecreator.h
    scenecreator.cpp
    )

add_library(scenecreator
    ${SOURCES}
    )

target_link_libraries(scenecreator PRIVATE Qt5::Widgets Qt5::Sql)
set_target_properties(scenecreator PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
