#include <algorithm>
#include <iostream>
#include <vector>

std::ostream &print(const std::vector<std::string> &words) {
    for (const auto &i : words) std::cout << i << ' ';
    return std::cout << std::endl;
}
void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    print(words);
    auto end_unique = std::unique(words.begin(), words.end());
    print(words);
    words.erase(end_unique, words.end());
    print(words);
}
int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"the",  "quick", "red", "fox",   "jumps",
                                      "over", "slow",  "red", "turtle"};
    print(words);
    elimDups(words);
    return 0;
}
