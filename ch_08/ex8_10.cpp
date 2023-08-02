#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::string> vs;
    std::string s;
    std::ifstream in("a.txt");
    while (std::getline(in, s)) vs.push_back(s);
    for (auto &i : vs) {
        std::istringstream is(i);
        while (is >> s) std::cout << s << ' ';
        std::cout << std::endl;
    }
    return 0;
}
