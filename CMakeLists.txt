cmake_minimum_required(VERSION 3.12)

project(ensnif)

set(CMAKE_CXX_STANDARD 14)

include_directories(SEAL/SEAL) 
link_directories(SEAL/bin)

add_subdirectory(rule_engine)
add_subdirectory(conversion)
add_subdirectory(ingestion)

#tls pcap demo
#add_executable(tls_pcap ingestion/tls_pcap.cpp conversion/tls_pcap.cpp rule_engine/tls_pcap.cpp ${LIBRARY_SOURCES})
#target_link_libraries(tls_pcap seal)

#unencrypted pcap demo
#add_executable(tls_pcap ingestion/tls_pcap.cpp conversion/tls_pcap.cpp rule_engine/tls_pcap.cpp ${LIBRARY_SOURCES})
#target_link_libraries(tls_pcap seal)