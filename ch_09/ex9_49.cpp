#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream infile("1.txt");
    std::string longest_word;
    for (std::string word; infile >> word;) {
        if (word.find_first_not_of("aceimnorsuvwxz") == std::string::npos &&
            word.size() > longest_word.size())
            longest_word = word;
    }
    std::cout << longest_word << std::endl;
    return 0;
}
