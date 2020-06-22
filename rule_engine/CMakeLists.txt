project(rule_engine)

add_library(${PROJECT_NAME} STATIC src/aho_corasick.cpp)
add_library(RULE_ENGINE::rule_engine ALIAS ${PROJECT_NAME})

target_include_directories (${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME}
    INGESTION::ingestion
)