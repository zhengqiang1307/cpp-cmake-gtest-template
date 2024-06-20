set(src
    main.cpp
    linklist_test.cpp
)

if(GTEST_FOUND)
    set(test_name ds_test)
    add_executable(${test_name} ${src})
    target_link_libraries(${test_name} gtest ds)
    add_test(${test_name} ${test_name})
endif()