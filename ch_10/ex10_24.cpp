#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;

bool checksize(const std::string &s, std::string::size_type sz) {
    return s.size() < sz;
}
int main(int argc, char *argv[]) {
    std::vector<int> ivec = {1, 2, 3, 4, 5};
    std::string word = "code";
    auto wc =
        std::find_if(ivec.begin(), ivec.end(), std::bind(checksize, word, _1));
    if (wc != ivec.end()) std::cout << *wc << std::endl;
    return 0;
}
