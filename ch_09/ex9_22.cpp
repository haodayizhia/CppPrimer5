#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    int some_value = 1;
    std::vector<int> iv = {1, 1, 1, 1, 1, 7, 1, 9};
    auto iter = iv.begin();
    auto cursor = iv.size() / 2;
    auto mid = iter + cursor;
    while (iter != mid) {
        if (*iter == some_value) {
            iter = iv.insert(iter, 2 * some_value);
            ++iter;
            ++cursor;
            mid = iv.begin() + cursor;
        }
        ++iter;
    }
    for (auto& i : iv) std::cout << i << ' ';
    std::cout << std::endl;
}
