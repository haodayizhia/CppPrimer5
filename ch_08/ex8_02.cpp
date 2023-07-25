#include <iostream>

std::istream &example(std::istream &in) {
    std::string s;
    while (in >> s) std::cout << s << std::endl;
    in.clear();
    return in;
}

int main(int argc, char *argv[]) {
    example(std::cin);
    return 0;
}
