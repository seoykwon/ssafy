#include <stdio.h>
void encrypt(char message[], char key) {
    for (int i = 0; message[i]; i++) {
        for (int j = 0; j < key; j++) {
            message[i] = (message[i] ^ key);
            message[i] = ((message[i] << 1) | ((message[i] & 0x40) >> 6)) & 0x7F;
            //0100 0000
            //0111 1111
            //0100 0011
            //1000 0110
            //1000 0111
            //0000 0111
        }
    }
}

void decrypt(char message[], char key) {
    for (int i = 0; message[i]; i++) {
        for (int j = 0; j < key; j++) {
            message[i] = (message[i] >> 1) | ((message[i] & 0x1) << 6);
            message[i] = (message[i] ^ key);
        }
    }
}

int main() {
    char message[3] = "AB";
    char key = 'A';
    printf("origin : %X%X\n", message[0], message[1]);
    encrypt(message, key);
    printf("encrypt : %X%X\n", message[0], message[1]);
    decrypt(message, key);
    printf("decrypt : %X%X\n", message[0], message[1]);
    char tmp1 = 0b00000010;
    char tmp2 = 0b00000001;
    printf("%x\n", tmp1);
    tmp1 = tmp1 ^ tmp2;
    printf("%x\n", tmp1);
    tmp1 = tmp1 ^ tmp2;
    printf("%x\n", tmp1);
}