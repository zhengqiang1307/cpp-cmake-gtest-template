set(target_name soundex)
add_library(${target_name} INTERFACE)
target_link_libraries(${target_name} INTERFACE pthread rt)
target_include_directories(${target_name} INTERFACE ${CMAKE_SOURCE_DIR}/chess/soundex)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/chess/soundex)

add_subdirectory(tests)