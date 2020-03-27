// C++17
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>


short int generateKey();

void recursive_encrypt(const std::string &message, const short int &key, std::string &temp, unsigned short int i = 0);

int main(int argc, char **argv) {
//    const std::string message = "Hello, Coders School!";
    const std::string message = argv[1];
    std::string temp = message;

    auto key = generateKey();

    recursive_encrypt(message, key, temp);
    auto cypher = temp;

    recursive_encrypt(cypher, 26 - key, temp);
    auto result = temp;

    std::cout << "Message: " << message << '\n';
    std::cout << "Cyphertext: " << cypher << '\n';
    std::cout << "Result: " << result << '\n';

    assert(message == result);
    return 0;
}

short int generateKey() {
    srand(std::time(nullptr));
    return rand() % 26;
}

void recursive_encrypt(const std::string &message, const short int &key,
                       std::string &temp, unsigned short int i) {
    if (i == message.size()) {
    } else {

        if (message[i] > 96 && message[i] < 123) {
            temp[i] = (message[i] - 97 + key) % 26 + 97;
        } else if (message[i] > 64 && message[i] < 91) {
            temp[i] = (message[i] - 65 + key) % 26 + 65;
        }
        recursive_encrypt(message, key, temp, ++i);
    }
}
