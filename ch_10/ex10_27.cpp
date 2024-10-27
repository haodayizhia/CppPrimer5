#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"i", "i", "love", "love", "you"};
    std::list<std::string> slst;
    std::unique_copy(words.cbegin(), words.cend(), std::back_inserter(slst));
    for (const auto &i : slst) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
