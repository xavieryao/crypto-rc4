#include "cstdio"
#include <iostream>
#include "RC4.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    char key[] = "Key";
    char plaintext[] = "Plaintext";

    auto rc4generator = RC4(key, 3);

    auto cipher = rc4generator.encrypt(plaintext, 9);
    for (int i = 0; i < 9; i++) {
        printf("%hhx ", cipher[i]);
    }
    return 0;
}