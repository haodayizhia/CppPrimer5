#include <iostream>
#include <vector>

int main() {
    std::vector<int> ivec;
    std::cout << "ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
    for (int i = 0; i < 10; ++i) ivec.push_back(i);
    std::cout << "ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
    while (ivec.size() != ivec.capacity()) ivec.push_back(0);
    std::cout << "ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
    ivec.push_back(42);
    std::cout << "ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
    return 0;
}
