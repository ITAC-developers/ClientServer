

add_executable(Server_test
        Server_test.cpp
)

target_link_libraries(
        Server_test
        gtest_main
        Server_lib
)

include(GoogleTest)
gtest_discover_tests(Server_test)

