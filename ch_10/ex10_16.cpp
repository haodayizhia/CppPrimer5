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
std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending) {
    return ctr > 1 ? word + ending : word;
}
void biggies(std::vector<std::string> words,
             std::vector<std::string>::size_type sz) {
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
                     [](const std::string &s1, const std::string &s2) {
                         return s1.size() < s2.size();
                     });
    auto wc =
        std::find_if(words.begin(), words.end(),
                     [sz](const std::string &s) { return s.size() > sz; });
    auto count = words.end() - wc;
    std::cout << count << ' ' << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(),
                  [](const std::string &s) { std::cout << s << ' '; });
    std::cout << std::endl;
}
int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"the",  "quick", "red", "fox",   "jumps",
                                      "over", "slow",  "red", "turtle"};
    print(words);
    biggies(words, 4);
    return 0;
}
