#include <deque>
#include <iostream>

int main() {
    std::string wd;
    std::deque<std::string> sd;
    while (std::cin >> wd) sd.push_back(wd);
    for (auto &i : sd) std::cout << i << ' ';
    std::cout << std::endl;
}
