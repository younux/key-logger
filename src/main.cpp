#include <iostream>
#include <windows.h>
#include "Helper.hpp"
#include "Base64.hpp"
#include "KeyConstants.hpp"
#include "IO.hpp"
#include "Timer.hpp"


int main() {

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}