add_executable(Logger_test
        Logger_test.cpp
)

target_link_libraries(
        Logger_test
        gtest_main
        common_lib
)

include(GoogleTest)
gtest_discover_tests(Logger_test)

