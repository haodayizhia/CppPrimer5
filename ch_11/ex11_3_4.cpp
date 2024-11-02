#include <algorithm>
#include <iostream>
#include <map>
#include <set>

void ex11_3(std::map<std::string, size_t> &word_count,
            std::set<std::string> &exclude) {
    std::string word;
    while (std::cin >> word)
        if (exclude.find(word) == exclude.end()) ++word_count[word];
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
}

void ex11_4(std::map<std::string, size_t> &word_count,
            std::set<std::string> &exclude) {
    std::string word;
    while (std::cin >> word) {
        std::for_each(word.begin(), word.end(),
                      [](char &c) { c = toupper(c); });
        word.erase(std::remove_if(word.begin(), word.end(),
                                  [](char &c) { return ispunct(c); }),
                   word.end());
        if (exclude.find(word) == exclude.end()) ++word_count[word];
    }
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
}

int main(int argc, char *argv[]) {
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "an", "a"};
    ex11_4(word_count, exclude);
}
