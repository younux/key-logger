//
// Created by younes.benhoumich on 10/02/2018.
//

#pragma once

#include <string>
#include <map>

class KeyPair {
public:
    KeyPair(const std::string &vk = "", const std::string &name="");
    ~KeyPair() {};

    std::string VKName;
    std::string Name;
};


class Keys{
public:
    static std::map<int, KeyPair> KEYS;
};


