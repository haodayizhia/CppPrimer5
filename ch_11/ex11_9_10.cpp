#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "ExerciseConfig.h"

int main(int argc, char *argv[]) {
    //! ex11.9
    std::map<std::string, std::list<size_t>> word_line;
    //! ex11.10
    std::map<std::vector<int>::iterator, int> vecit_int;
    std::map<std::list<int>::iterator, int> lstit_int;
    std::vector<int> ivec = {1, 2};
    std::list<int> ilst = {1, 2};
    vecit_int[ivec.begin()] = 1;
    // 报错提示error: no match for 'operator<' (operand types are 'const
    // std::_List_iterator<int>' and 'const std::_List_iterator<int>')  386 | {
    // return __x < __y; } 这是由于map按关键字顺序保存, 要求关键字支持<运算符
    lstit_int[ilst.begin()] = 1;
    return 0;
}
