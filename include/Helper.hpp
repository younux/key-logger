//
// Created by younes.benhoumich on 10/02/2018.
//

#pragma once

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper {

    template <class T> std::string ToString(const T&);

    struct DateTime{
        DateTime();
        DateTime(int D, int m, int y, int H, int M, int S);
        DateTime(int D, int m, int y);

        DateTime Now() const;

        std::string GetDateString() const;
        std::string GetTimeString(const std::string &sep=":") const;
        std::string GetDateTimeString(const std::string &sep=":") const;

        int D;
        int m;
        int y;
        int H;
        int M;
        int S;
    };

    void WriteAppLog(const std::string &s);
}
