#include <list>
#include <iostream>

int main() {
    std::string wd;
    std::list<std::string> sl;
    while (std::cin >> wd) sl.push_back(wd);
    for (auto i = sl.begin(); i != sl.end(); ++i) std::cout << *i << ' ';
    std::cout << std::endl;
}
