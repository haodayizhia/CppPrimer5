#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> ivec1 = {1, 2, 3};
    std::vector<int> ivec2 = {4, 5, 6};
    std::cout << (ivec1 < ivec2) << std::endl;
    return 0;
}
