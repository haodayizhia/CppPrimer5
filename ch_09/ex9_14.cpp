#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "ExerciseConfig.h"

int main(int argc, char *argv[]) {
    std::list<char *> lc{"i", "do", "a", "test"};
    std::vector<std::string> vs;
    vs.assign(lc.begin(), lc.end());
    for (const auto &i : vs) std::cout << i << ' ';
    return 0;
}
