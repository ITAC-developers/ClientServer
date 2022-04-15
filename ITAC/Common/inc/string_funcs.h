#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace ITAC::common
{

/**
 * @brief Erase all whitespace symbols from left side of string in place
 * @param[in] s Input string that to be trimmed
 * @return      Reference to the same string that was trimmed
 */
std::string& ltrim(std::string& s);

/**
 * @brief  Erase all whitespace symbols from right side of string in place
 * @param[in] s Input string that to be trimmed
 * @return      Reference to the same string that was trimmed
 */
std::string& rtrim(std::string& s);

/**
 * @brief Erase all whitespace symbols from left and right size of string in place
 * @param[in] s Input string that to be trimmed
 * @return      Refernce to the same string that was trimmed
 */
std::string& trim(std::string& s);

/**
 * @Brief Split string sv by each character in spitters
 * @param sv         Input string for split
 * @param splitters  Set of characters
 * @return           Vector of strings_view after split string
 */
std::vector<std::string_view> Split(std::string_view sv, std::string_view splitters);

} //namespace ITAC::common
