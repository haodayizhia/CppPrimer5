#include <iostream>
#include <string>

int main() {
    std::string s("ab2c3d7R4E6");
    std::string numbers("0123456789");
    std::string::size_type pos = 0;
    // find_first_not_of版本
    while ((pos = s.find_first_not_of(alph, pos)) != std::string::npos) {
        std::cout << "found number at index: " << pos << " element is "
                  << s.at(pos) << std::endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {
        std::cout << "found alph at index: " << pos << " element is "
                  << s.at(pos) << std::endl;
        ++pos;
    }
}
