//
// Created by 沛然 姚 on 2017/4/19.
//

#include <cassert>
#include "RC4.h"

RC4::RC4(char *key, int keyLen) {
    this->key = key;
    this->keyLen = keyLen;
    reset();
}

void RC4::reset() {
    _i = 0;
    _j = 0;
    for (int i = 0; i < 256; ++i) {
        S[i] = (Byte) i;
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j+S[i]+key[i % keyLen]) % 256;
        if (j < 0) {
            j += 256;
        }
        std::swap(S[i], S[j]);
    }
}

/*
 * generate a pseudo-random byte
 */
Byte RC4::generate() {
    _i = (_i+1) % 256;
    _j = (_j+S[_i]) % 256;

    std::swap(S[_i], S[_j]);
    return S[(S[_i] + S[_j]) % 256];
}

char* RC4::encrypt(char *plaintext, int plaintextLen) {
    auto ciphertext = new char[plaintextLen];
    for (int i = 0; i < plaintextLen; i++) {
        ciphertext[i] = plaintext[i] ^ generate();
    }
    return ciphertext;
}



