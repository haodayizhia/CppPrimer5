#include <algorithm>
#include <iostream>
#include <vector>

bool lengthThan5(const std::string &word) { return word.size() > 5; }

int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"I",     "am",      "not",   "here",
                                      "today", "because", "coding"};
    auto Splitpoint = std::partition(words.begin(), words.end(), lengthThan5);
    for (auto it = words.cbegin(); it < Splitpoint; ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
