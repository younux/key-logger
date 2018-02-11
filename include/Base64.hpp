//
// Created by younes.benhoumich on 10/02/2018.
//

#pragma once

#include <vector>
#include <string>


namespace Base64{

    std::string base64_encode(const std::string &);

    const std::string SALT1 = "LM:/TR:DS:JI";
    const std::string SALT2 = "_hhz_szmk_HD*z";
    const std::string SALT3 = "linde::_wols++=s";

    std::string EncryptB64(std::string s);

    const std::string BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

}
