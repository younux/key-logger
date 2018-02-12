//
// Created by younes.benhoumich on 11/02/2018.
//
#include "IO.hpp"

namespace IO {
    std::string GetOurPath(const bool append_separator){
        std::string appdata_dir(getenv(APP_DATA_ENV_VAR_NAME));
        std::string full = appdata_dir + APP_DIR_INSIDE_APP_DATA_ROAMING;
        return full + (append_separator ? "\\" : "");
    }

    bool MkOneDir(std::string path){
        return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
    }

    bool MkDir(std::string path){
        for(char &c : path){
            if(c == '\\'){
                c = '\0';
                if(!MkOneDir(path)){
                    return false;
                }
                c = '\\';
            }
        }
        return true;
    }
}
