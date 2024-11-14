#include <iostream>
#include <map>
#include <vector>

int main(int argc, char *argv[]) {
    std::multimap<std::string, std::string> m1 = {{"author1", "book1"},
                                                  {"author1", "book2"}};
    std::cout << "author1" << ": ";
    for (auto pos = m1.equal_range("author1"); pos.first != pos.second;) {
        std::cout << pos.first->second << " ";
        pos.first = m1.erase(pos.first);
    }
    std::cout << std::endl;
    for (auto beg = m1.begin(); beg != m1.end(); ++beg)
        std::cout << beg->first << ": " << beg->second << std::endl;
    return 0;
}
