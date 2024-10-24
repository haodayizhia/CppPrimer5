#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int i = 3;
    auto f = [&i]() -> bool {
        if (i == 0)
            return true;
        else {
            --i;
            return false;
        }
    };
    while (!f()) std::cout << i << std::endl;
    return 0;
}
