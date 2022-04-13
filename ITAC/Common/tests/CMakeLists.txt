add_executable(common_test
        Logger_test.cpp
        FS_test.cpp
)

target_link_libraries(
        common_test
        gtest_main
        common_lib
)

include(GoogleTest)
gtest_discover_tests(common_test)
