#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::ifstream in("a.txt");
    std::istream_iterator<std::string> in_iter(in), eof;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::vector<std::string> words(in_iter, eof);
    std::copy(words.cbegin(), words.cend(), out_iter);
    std::cout << std::endl;
}
