//
// Created by sormunen on 6.11.2019.
//

#ifndef TDDSOUNDEX_STRINGUTIL_H
#define TDDSOUNDEX_STRINGUTIL_H

#include <string>

class stringUtil {
public:
    static std::string upperFront(const std::string& string) {
        return std::string(1, std::toupper(static_cast<unsigned char>(string.front())));
    }

    static std::string head(const std::string& word) {
        return word.substr(0,1);
    }

    static std::string tail(const std::string& word) {
        return word.substr(1);
    }
};


#endif //TDDSOUNDEX_STRINGUTIL_H
