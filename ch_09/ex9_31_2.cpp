#include <forward_list>
#include <iostream>

int main(int argc, char *argv[]) {
    std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = fli.begin();
    auto prev = fli.before_begin();
    while (iter != fli.end()) {
        if (*iter % 2) {
            iter = fli.insert_after(iter, *iter);
            prev = iter;
            ++iter;
        } else
            iter = fli.erase_after(prev);
    }
    for (auto &i : fli) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
