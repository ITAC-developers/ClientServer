#include <FS.h>

#include <filesystem>

namespace ITAC::common::FS
{

bool CloseLogFile(const std::filesystem::path& file)
{
    (void)file;
    return true;
}

bool OpenLogFile(const std::filesystem::path& file, std::ostream* stream)
{
    if (std::filesystem::exists(file))
    {
        *stream(file)
    }
    (void)file;
    (void)stream;
    return true;
}

} //namespace ITAC::common::FS

