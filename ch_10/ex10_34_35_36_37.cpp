#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 10.34
    for (auto i = ivec.crbegin(); i != ivec.crend(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
    // 10.35
    for (auto i = ivec.cend(); i != ivec.cbegin();) std::cout << *--i << ' ';
    std::cout << std::endl;
    // 10.36
    std::list<int> ilst1 = {1, 2, 0, 3};
    auto found = std::find(ilst1.crbegin(), ilst1.crend(), 0);
    // 10.37
    std::list<int> ilst2;
    std::copy(ivec.crbegin() + ivec.size() - 7,
              ivec.crbegin() + ivec.size() - 2, std::back_inserter(ilst2));
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(ilst2.cbegin(), ilst2.cend(), out);
}
