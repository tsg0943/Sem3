#include <iostream>

int pow(int num, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp > 0) {
        int result = 1;

        for (int i = 0; i < exp; ++i) {
            result *= num;
        }
        return result;
    }
    return -1;
}

unsigned int char2int(char chr) {
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'A' && chr <= 'F')
        return chr - 'A' + 10;
    return -1;
}

int hex2dec(const char *hex, int size) {
    int dec = 0;
    for (int j = 0, i = size - 1; j < size; ++j, --i) {
        dec += char2int(hex[j]) * pow(16, i);
    }
    return dec;
}

int main(int argc, char *argv[]) {
    std::string hex;
    for (int i = argc - 1; i > 0; i--){
        hex = argv[i];
        int dec = hex2dec(hex.c_str(), hex.length());
        std::cout << dec + 106 << std::endl;
    }
    return 0;
}
