#include <iostream>
using namespace std;

void encrypt(char message[], char key) {
	for (int i = 0; message[i]; i++) {
		for (int j = 0; j < key; j++) {
			message[i] = (message[i] ^ key);
			//message[i] = ((message[i] << 1) | ((message[i] & 0x40) >> 6)) & 0x7F;
		}
	}
}

void decrypt(char message[], char key) {
	for (int i = 0; message[i]; i++) {
		for (int j = 0; j < key; j++) {
			//message[i] = ((message[i] >> 1) | ((message[i] | 0x40) << 6)) | 0x7F;
			message[i] = (message[i] ^ ~key);
			cout << "hey" << endl;
		}
	}
}

int main() {
	char message[3] = "AB";
	char key = 'A';
	printf("origin: %X%X\n", message[0], message[1]);
	encrypt(message, key);
	printf("encrypt : %X%X\n", message[0], message[1]);
	decrypt(message, key);
	printf("decrypt : %X%X\n", message[0], message[1]);
}