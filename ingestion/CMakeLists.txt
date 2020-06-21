project(ingestion)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/data_ingestion.cpp)
add_library(ingestion_lib ALIAS ${PROJECT_NAME})

target_include_directories (${PROJECT_NAME}
 PUBLIC ${PROJECT_SOURCE_DIR}/include
)