project(demo)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    ingestion
    rule_engine
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)