find_package(Qt6 REQUIRED COMPONENTS Sql)

set(SOURCES
    idbcontroller.h
    pgdbcontroller.h
    pgdbcontroller.cpp
    )

add_library(dbcontroller
    ${SOURCES}
    )

set(CREATE_DB_SCRIPT_PATH "..//..//db_script//init_db.sql")

set(PSQL_PATH "C:\\Program Files\\PostgreSQL\\15\\bin")

add_custom_command(
    TARGET dbcontroller
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E env PGPASSWORD=postgres ${PSQL_PATH}\\psql -h localhost -p 5432 -U postgres -d postgres -a -q -f ${CREATE_DB_SCRIPT_PATH}
    COMMENT "Creating database"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    VERBATIM
)

target_link_libraries(dbcontroller PRIVATE Qt6::Sql)
target_link_libraries(dbcontroller PRIVATE PostgreSQL::PostgreSQL)
set_target_properties(dbcontroller PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
