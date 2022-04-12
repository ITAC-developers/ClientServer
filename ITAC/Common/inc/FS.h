#pragma once

#include <filesystem>
#include <iostream>

namespace ITAC::common::FS
{

bool CloseLogFile(const std::filesystem::path& file);
bool OpenLogFile(const std::filesystem::path& file, std::ostream* stream);

}

