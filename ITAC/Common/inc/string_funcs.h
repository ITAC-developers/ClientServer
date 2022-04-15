#pragma once

#include <string>

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

} //namespace ITAC::common
