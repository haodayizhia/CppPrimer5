#include <algorithm>
#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
    std::vector<int> ivec = {1, 2, 3};
    std::fill_n(ivec.begin(), ivec.size(), 0);
    for (const auto &i : ivec) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
