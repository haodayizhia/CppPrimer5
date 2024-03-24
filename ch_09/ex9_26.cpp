#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> iv(std::begin(ia), std::end(ia));
    std::list<int> il(std::begin(ia), std::end(ia));
    for (auto it = iv.begin(); it != iv.end();) {
        if (!(*it & 1))
            it = iv.erase(it);
        else
            ++it;
    }
    for (auto &i : iv) std::cout << i << ' ';
    std::cout << std::endl;
    for (auto it = il.begin(); it != il.end();) {
        if (*it & 1)
            it = il.erase(it);
        else
            ++it;
    }
    for (auto &i : il) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
