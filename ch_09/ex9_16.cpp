#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    std::list<int> list = {1, 2, 3};
    std::vector<int> ivec = {4, 5, 6};
    std::cout << (list < ivec) << std::endl;
    return 0;
}
