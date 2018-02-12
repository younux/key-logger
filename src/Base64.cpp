//
// Created by younes.benhoumich on 10/02/2018.
//

#include "Base64.hpp"
#include "DEFINITIONS.hpp"

namespace Base64{

    const std::string SALT1 = SALT1_CONTENT;
    const std::string SALT2 = SALT2_CONTENT;
    const std::string SALT3 = SALT3_CONTENT;

    const std::string BASE64_CODES = BASE64_CODES_CONTENT;

    std::string EncryptB64(std::string s){
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

    std::string base64_encode(const std::string & s){
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;
        for(const auto &c : s){
            val = (val << 8) + c;
            bits += 8;
            while(bits >= 0){
                ret.push_back(BASE64_CODES[(val >> bits & b63)]);
                bits -= 6;
            }
        }
        if(bits > -6){
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);
        }
        while (ret.size() % 4){
            ret.push_back('=');
        }
        return ret;
    }
}