//
// Created by sormunen on 10.10.2019.
//

#ifndef TDDSOUNDEX_SOUNDEX_H
#define TDDSOUNDEX_SOUNDEX_H

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return zeroPad(word);
    }
private:
    std::string zeroPad(const std::string &word) const {
        return word + "000";
    }
};

#endif //TDDSOUNDEX_SOUNDEX_H