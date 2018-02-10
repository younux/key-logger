//
// Created by younes.benhoumich on 10/02/2018.
//

#include "Base64.hpp"


namespace Base64{

    std::string Encrypt64(std::string s){
        s = SALT1 + s + SALT2 + SALT3;
        s = base64_encode(s);
        s.insert(7, SALT3);
        s += SALT1;
        s = base64_encode(s);
        s += SALT2 + SALT3 + SALT1;
        s = base64_encode(s);
        s.insert(1, "L");
        s.insert(7, "M");
        return s;
    }
}