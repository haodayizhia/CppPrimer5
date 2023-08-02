#include <iostream>
#include <sstream>

std::istream &example(std::istream &in) {
    std::string s;
    while (in >> s) std::cout << s << std::endl;
    in.clear();
    return in;
}

int main(int argc, char *argv[]) {
    std::cout << "Exercise VERSION " << Exercise_VERSION_MAJOR << '.'
              << Exercise_VERSION_MINOR << std::endl;
    std::string s = "i want see";
    std::istringstream is(s);
    example(is);
    return 0;
}
