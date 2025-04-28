#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    char c1[] = "hello ";
    char c2[] = "world";
    std::string s1 = "hello ";
    std::string s2 = "world";
    size_t len = std::strlen(c1) + std::strlen(c2) + 1;
    char* c3 = new char[len];
    std::strcat(c3, c1);
    std::strcat(c3, c2);
    std::cout << c3 << std::endl;
    std::strcpy(c3, (s1 + s2).c_str());
    std::cout << c3 << std::endl;
    delete[] c3;
    return 0;
}
