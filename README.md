# key-logger

This is a key logger built from scratch using C++

 ## Note :
 * This program is only created for educational and learning purposes.
 * This keylogger can cause serious damage so use it for good, for learning and in a legal and responsible way.
 * This program should never be used in an illegal way (hacking someone ...).

The program is standalone and does not require any external library, which is
very important for a key logger (no installation needed).

The program is only compatible with Windows 7 and above as it is using Powershell and Windows C++ API.

The program is able to intercept any keystroke.

The recorded keystrokes are crypted and put in a file that is sent by email.

The build is done using cmake.

The test was done using mingw-w64 32bits compiler.

Try to compile it with MSVC (for avoiding non Microsoft dependencies like
  mingw libraries) (I didn't test to compile it with MSVC)

Do not forget to configure the email address and its password in DEFINITIONS.hpp (to send the
recorded keyboard strokes).

You can also change the mail timer (the period of sending emails with keyboard strokes) in
DEFINITIONS.hpp (MAIL_TIMER_MINUTES).
