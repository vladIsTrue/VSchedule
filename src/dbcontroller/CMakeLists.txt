find_package(Qt6 REQUIRED COMPONENTS Sql)

set(SOURCES
    idbcontroller.h
    pgdbcontroller.h
    pgdbcontroller.cpp
    )

add_library(dbcontroller
    ${SOURCES}
    )

target_link_libraries(dbcontroller PRIVATE Qt6::Sql)
target_link_libraries(dbcontroller PRIVATE PostgreSQL::PostgreSQL)
set_target_properties(dbcontroller PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
