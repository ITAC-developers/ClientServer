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

TEST(string_funcs, split)
{
    struct InputS { std::string str; std::string splitter; };
    std::vector<InputS> input =
    {
        {"", ""},
        {"word", " "},
        {"word word2 word3", " "},
        {"", " o"},
        {"word", " o"},
        {"word word2 word3", " o"}
    };
    std::vector<std::vector<std::string_view>> expected = {
    	{},
    	{ "word" },
    	{ "word", "word2", "word3" },
    	{},
    	{ "w", "rd" },
    	{ "w", "rd", "w", "rd2", "w", "rd3" }
    };
    auto i_it = input.begin();
    auto e_it = expected.begin();
    for (; i_it != input.end() && e_it != expected.end(); ++i_it, ++e_it)
    {
        auto result = ITAC::common::Split(i_it->str, i_it->splitter);
        ASSERT_EQ(result.size(), e_it->size());
        for (std::size_t i = 0; i < result.size(); ++i)
        {
            result[i].compare((*e_it)[i]);
            EXPECT_EQ(result[i].compare((*e_it)[i]), 0);
        }
    }
}

