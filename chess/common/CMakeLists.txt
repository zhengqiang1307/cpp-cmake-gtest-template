set(src
    StringUtil.cpp
)

add_library(common SHARED ${src})
target_link_libraries(common PUBLIC pthread rt)
target_include_directories(common PUBLIC ${CMAKE_SOURCE_DIR}/chess/common)

install(TARGETS common DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/chess/common)

add_subdirectory(tests)
