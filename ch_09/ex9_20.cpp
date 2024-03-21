#include <deque>
#include <iostream>
#include <list>

int main() {
    int num;
    std::list<int> l = {1, 2, 3, 4, 5};
    std::deque<int> d1, d2;
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        if ((*iter) % 2)
            d1.push_back(*iter);
        else
            d2.push_back(*iter);
    }
    std::cout << "d1: ";
    for (auto &i : d1) std::cout << i << ' ';
    std::cout << std::endl;
    std::cout << "d2: ";
    for (auto &i : d2) std::cout << i << ' ';
}
