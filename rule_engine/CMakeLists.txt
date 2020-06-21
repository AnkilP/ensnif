project(rule_engine)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/rule_engine.cpp)

target_include_directories (${PROJECT_NAME}
 PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    ingestion_lib
)