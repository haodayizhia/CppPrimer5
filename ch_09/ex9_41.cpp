#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<char> cvec = {'a', 'i'};
    std::string s(cvec.begin(), cvec.end());
    std::cout << s << std::endl;
    return 0;
}
