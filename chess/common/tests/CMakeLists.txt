set(src
    main.cpp
    CharUtilTest.cpp
    StringUtilTest.cpp
)

if(GTEST_FOUND)
    set(test_name common_test)
    add_executable(${test_name} ${src})
    target_link_libraries(${test_name} pthread gtest common)
    add_test(${test_name} ${test_name})
endif()