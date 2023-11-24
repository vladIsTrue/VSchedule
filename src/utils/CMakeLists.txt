find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(SOURCES
    utils.h
    )

add_library(utils
    ${SOURCES}
    )

target_link_libraries(utils PRIVATE Qt${QT_VERSION_MAJOR}::Core)
set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
