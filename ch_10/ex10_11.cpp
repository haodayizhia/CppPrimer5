#include <algorithm>
#include <iostream>
#include <vector>

std::ostream &print(const std::vector<std::string> &words) {
    for (const auto &i : words) std::cout << i << ' ';
    return std::cout << std::endl;
}
bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
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
    std::stable_sort(words.begin(), words.end(), isShorter);
    print(words);
    return 0;
}
