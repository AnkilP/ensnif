project(ingestion)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/rule_ingestion.cpp ${PROJECT_SOURCE_DIR}/src/packet_ingestion.cpp)
add_library(ingestion_lib ALIAS ${PROJECT_NAME})

target_include_directories (${PROJECT_NAME}
 PUBLIC ${PROJECT_SOURCE_DIR}/include
)