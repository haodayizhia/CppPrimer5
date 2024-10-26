#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;

bool checksize(const std::string &s, std::string::size_type sz) {
    return s.size() > sz;
}
int main(int argc, char *argv[]) {
    std::vector<std::string> words = {"The", "only",        "limit", "to",
                                      "our", "realization", "of",    "tomorrow",
                                      "is",  "today"};
    std::string::size_type sz = 6;
    auto count =
        std::count_if(words.begin(), words.end(), std::bind(checksize, _1, sz));
    std::cout << count << std::endl;
    return 0;
}
