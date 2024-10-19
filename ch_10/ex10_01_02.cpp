#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
int main(int argc, char *argv[]) {
    // 10.1
    std::vector<int> ivec = {1, 2, 3, 1, 4, 6, 1};
    std::cout << std::count(ivec.cbegin(), ivec.cend(), 1) << std::endl;

    // 10.2
    std::list<std::string> slst = {"Sow", "nothing", ",", "reap", "nothing"};
    std::cout << std::count(slst.cbegin(), slst.cend(), "nothing") << std::endl;
}
