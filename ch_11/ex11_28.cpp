#include <iostream>
#include <map>
#include <vector>

int main(int argc, char *argv[]) {
    std::map<std::string, std::vector<int>> m1 = {{"one", {1}}};
    std::map<std::string, std::vector<int>>::iterator it = m1.find("one");
    if (it != m1.end()) std::cout << "found " << it->first << std::endl;
    return 0;
}
