#pragma once

#include <filesystem>

inline std::filesystem::path operator "" _p(const char *path, std::size_t sz)
{
    return {path, path + sz};
}

