#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    std::list<int> il = {1, 2, 3};
    std::vector<int> ivec = {1, 2, 3};
    std::vector<double> dvec1(il.begin(), il.end());
    std::vector<double> dvec2(ivec.begin(), ivec.end());
    return 0;
}
