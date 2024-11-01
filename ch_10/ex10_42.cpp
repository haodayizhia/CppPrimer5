#include <iostream>
#include <list>

std::ostream &print(const std::list<std::string> &words) {
    for (const auto &i : words) std::cout << i << ' ';
    return std::cout << std::endl;
}
void elimDups(std::list<std::string> &words) {
    words.sort();
    print(words);
    auto end_unique = words.unique();
    print(words);
}
int main(int argc, char *argv[]) {
    std::list<std::string> words = {"the",  "quick", "red", "fox",   "jumps",
                                    "over", "slow",  "red", "turtle"};
    print(words);
    elimDups(words);
    return 0;
}
