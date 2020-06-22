project(ingestion)

add_library(${PROJECT_NAME} src/data_ingestion.cpp)
#add_library(ingestion ALIAS ${PROJECT_NAME})

target_include_directories (${PROJECT_NAME}
 PUBLIC ${PROJECT_SOURCE_DIR}/include
)