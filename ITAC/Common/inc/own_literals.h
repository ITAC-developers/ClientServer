#pragma once

#include <filesystem>

/**
 * @brief String literal _p for create std::filesystem::path object
 * @param path C-style string that contain path
 * @param sz   size of path
 * @return     new std::filesystem::path
 */
inline std::filesystem::path operator "" _p(const char *path, std::size_t sz)
{
    return {path, path + sz};
}
