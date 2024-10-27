#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> back_ivec;
    std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(back_ivec));
    for (auto const &i : back_ivec) std::cout << i << ' ';
    std::cout << std::endl;

    std::list<int> front_lst;
    std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(front_lst));
    for (auto const &i : front_lst) std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<int> inserter_ivec;
    std::copy(ivec.cbegin(), ivec.cend(),
              std::inserter(inserter_ivec, inserter_ivec.begin()));
    for (auto const &i : inserter_ivec) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
