//
// Created by 沛然 姚 on 2017/4/19.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H

#include <algorithm>
#include <cstdlib>

typedef unsigned char Byte;

class RC4 {
private:
    Byte S[256];
    int _i, _j;
    char* key;
    int keyLen;

public:
    RC4(char* key, int keyLen);
    void reset();
    Byte generate();
    char* encrypt(char* plaintext, int plaintextLen);
};


#endif //RC4_RC4_H
