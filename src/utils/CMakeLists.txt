find_package(Qt5 REQUIRED COMPONENTS Core)

set(SOURCES
    utils.h
    )

add_library(utils
    ${SOURCES}
    )

target_link_libraries(utils PRIVATE Qt5::Core)
set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
