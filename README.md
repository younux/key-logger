# key-logger

This is a key logger built from scratch using C++

The program is standalone and does not require any external library, which is
very important for a key logger (no installation needed).

 ## Note :
 * This program is only created for educational and learning purposes.
 * This keylogger can cause serious damage so use it for good, for learning and in a legal and responsible way.
 * This program should never be used in an illegal way (hacking someone ...).

The build is done using cmake.

The given bin (inside /bin) was compiled using mingw-w64 32bits.

Do not forget to configure the email address and its password in DEFINITIONS.hpp (to send the
recorded keyboard strokes).

You can also change the mail timer (the period of sending emails with keyboard strokes) in
DEFINITIONS.hpp (MAIL_TIMER_MINUTES).
