#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"the",  "quick", "red", "fox",   "jumps",
                                      "over", "slow",  "red", "turtle"};
    auto count =
        std::count_if(words.begin(), words.end(),
                      [](const std::string &s) { return s.size() > 6; });
    std::cout << count << std::endl;
    return 0;
}
