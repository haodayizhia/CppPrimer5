#include <cstring>
#include <iostream>
#include <limits>

int main(int argc, char* argv[]) {
    size_t size{0};
    std::cout << "The length of string will be: " << std::endl;
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* cp = new char[size + 1];
    std::cout << "input the string:" << std::endl;
    // 超出长度的字符会被忽略
    std::cin.getline(cp, size + 1);
    std::cout << cp << std::endl;
    delete[] cp;
    return 0;
}
