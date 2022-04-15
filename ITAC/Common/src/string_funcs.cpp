#include <string_funcs.h>
#include <algorithm>

namespace ITAC::common {

std::string &ltrim(std::string &s) {
    auto last_ws = std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    s.erase(s.begin(), last_ws);
    return s;
}

std::string &rtrim(std::string &s) {
    auto first_ws = std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    s.erase(first_ws.base(), s.end());
    return s;
}

std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

} //namespace ITAC::common