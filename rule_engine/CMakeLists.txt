project(rule_engine)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/aho_corasick.cpp)
add_library(rule_parser ALIAS ${PROJECT_NAME})

target_include_directories (${PROJECT_NAME}
 PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    ingestion_lib
)