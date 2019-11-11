//
// Created by sormunen on 6.11.2019.
//

#ifndef TDDSOUNDEX_CHARUTIL_H
#define TDDSOUNDEX_CHARUTIL_H

#include <cctype>
#include <string>

class charUtil {
public:
    static char lower(const char c) {
        return std::tolower(static_cast<unsigned char>(c));
    }

    static bool isVowel(const char letter) {
        return std::string("aeiouy").find(charUtil::lower(letter)) != std::string::npos;
    }
};


#endif //TDDSOUNDEX_CHARUTIL_H
