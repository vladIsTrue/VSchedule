find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

set(SOURCES
    scenecreator.h
    scenecreator.cpp
    )

add_library(scenecreator
    ${SOURCES}
    )

target_link_libraries(scenecreator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(scenecreator PRIVATE Qt6::Sql)
set_target_properties(scenecreator PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
