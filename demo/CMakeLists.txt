project(demo)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    RULE_ENGINE::rule_engine
    INGESTION::ingestion
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)