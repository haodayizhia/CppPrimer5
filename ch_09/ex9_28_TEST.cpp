#include <forward_list>
#include <iostream>

void temp(std::forward_list<std::string> &flst, std::string s1,
          std::string s2) {
    auto it = flst.begin();
    while (*it != s1 && it != flst.end()) ++it;
    flst.insert_after(it, s2);
}

int main(int argc, char *argv[]) {
    std::forward_list<std::string> flst = {"i", "love", "you"};
    std::string s1 = "you";
    std::string s2 = "too";
    temp(flst, s1, s2);
    for (auto i : flst) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
