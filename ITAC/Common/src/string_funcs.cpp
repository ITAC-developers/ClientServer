#include <string_funcs.h>

#include <algorithm> //find_if

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

std::vector<std::string_view> Split(std::string_view sv, std::string_view splitters) {
    std::vector<std::string_view> result;
    if (sv.empty()) return {};
    if (splitters.empty()) return {sv};
    while (sv.size() > 0) {
        auto pos = sv.find_first_of(splitters);
        result.push_back(sv.substr(0, pos));
        if (pos == std::string_view::npos) {
            break;
        }
        sv.remove_prefix(pos + 1);
    }
    return result;
}

} //namespace ITAC::common

