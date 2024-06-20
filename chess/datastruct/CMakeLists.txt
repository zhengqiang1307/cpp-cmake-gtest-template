set(src
  linklist.cpp
)

set(tn ds)
add_library(${tn} SHARED ${src})
target_link_libraries(${tn} PUBLIC pthread rt)
target_include_directories(${tn} PUBLIC ${CMAKE_SOURCE_DIR}/chess/datastruct)

install(TARGETS ${tn} DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/chess/datastruct)

add_subdirectory(tests)