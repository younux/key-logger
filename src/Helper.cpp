//
// Created by younes.benhoumich on 10/02/2018.
//

#include "Helper.hpp"


namespace Helper {

    template <class T> std::string ToString(const T &e){
        std::ostringstream s;
        s << e;
        return s.str();
    }

    DateTime::DateTime() {
        time_t ms;
        time(&ms);

        struct tm *info = localtime(&ms);
        D = info->tm_mday;
        m = info->tm_mon + 1;
        y = info->tm_year + 1900;
        M = info->tm_min;
        H = info->tm_hour;
        S = info->tm_sec;
    }

    DateTime::DateTime(int D, int m, int y, int H, int M, int S):
        D(D), m(m), y(y), H(H), M(M), S(S){

    }

    DateTime::DateTime(int D, int m, int y):
        D(D), m(m), y(y), H(0), M(0), S(0){

    }

    DateTime DateTime::Now() const {
        return DateTime();
    }

    std::string DateTime::GetDateString() const {
        return std::string( D < 10 ? "0" : "") + ToString(D) + std::string( m < 10 ? ".0" : ".") + ToString(m)
                + "." + ToString(y);

    }

    std::string DateTime::GetTimeString(const std::string &sep) const {
        return std::string( H<10 ? "0" : "") + ToString(H) + sep + std::string( M<10 ? "0" : "") + ToString(M)
                + sep +  std::string( S < 10 ? "0" : "") + ToString(S);
    }

    std::string DateTime::GetDateTimeString(const std::string &sep) const {
        return GetDateString() + " " + GetDateTimeString(sep);
    }

    void WriteAppLog(const std::string &s){
        std::ofstream file("AppLog.txt", std::ios::app);
        DateTime dateTime = DateTime();
        file << "[" << dateTime.GetDateTimeString() << "]" << " : " << s << std::endl << "\n";
        file.close();
    }
}