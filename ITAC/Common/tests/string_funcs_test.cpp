#include <gtest/gtest.h>

#include <string_funcs.h>

TEST(string_funcs, rtrim)
{
    std::vector<std::string> input = {
        "",
        "\t \t",
        "  \tword and word",
        "word and word \t ",
        "  \tword and word \t "
    };
    std::vector<std::string> expected = {
        "",
        "",
        "  \tword and word",
        "word and word",
        "  \tword and word"
    };
    auto i_it = input.begin();
    auto e_it = expected.begin();
    for (; i_it != input.end() && e_it != expected.end(); ++i_it, ++e_it)
    {
        EXPECT_STREQ(ITAC::common::rtrim(*i_it).c_str(), e_it->c_str());
    }
}

TEST(string_funcs, ltrim)
{
    std::vector<std::string> input = {
            "",
            "\t \t",
            "  \tword and word",
            "word and word \t ",
            "  \tword and word \t "
    };
    std::vector<std::string> expected = {
            "",
            "",
            "word and word",
            "word and word \t ",
            "word and word \t "
    };
    auto i_it = input.begin();
    auto e_it = expected.begin();
    for (; i_it != input.end() && e_it != expected.end(); ++i_it, ++e_it)
    {
        EXPECT_STREQ(ITAC::common::ltrim(*i_it).c_str(), e_it->c_str());
    }
}

TEST(string_funcs, trim)
{
    std::vector<std::string> input = {
            "",
            "\t \t",
            "  \tword and word",
            "word and word \t ",
            "  \tword and word \t "
    };
    std::vector<std::string> expected = {
            "",
            "",
            "word and word",
            "word and word",
            "word and word"
    };
    auto i_it = input.begin();
    auto e_it = expected.begin();
    for (; i_it != input.end() && e_it != expected.end(); ++i_it, ++e_it)
    {
        EXPECT_STREQ(ITAC::common::trim(*i_it).c_str(), e_it->c_str());
    }
}