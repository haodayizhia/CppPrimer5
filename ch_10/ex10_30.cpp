#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::vector<int> ivec;
    std::copy(in_iter, eof, std::back_inserter(ivec));
    std::sort(ivec.begin(), ivec.end());
    std::copy(ivec.cbegin(), ivec.cend(), out_iter);
    std::cout << std::endl;
}
