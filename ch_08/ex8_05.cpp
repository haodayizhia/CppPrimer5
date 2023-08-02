#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::string> vs;
    std::string s;
    std::ifstream in("a.txt");
    while (in >> s) vs.push_back(s);
    for (auto &i : vs) std::cout << i << std::endl;
    return 0;
}
