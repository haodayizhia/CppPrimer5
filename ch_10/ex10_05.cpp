#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
int main(int argc, char *argv[]) {
    char c1[] = "张三";
    char c2[] = "张三";
    std::vector<char *> roster1 = {c1};
    std::list<char *> roster2 = {c2};
    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin())
              << std::endl;
    // 为0. 返回两个序列对应元素char*的比较值, 比较的是地址.
    // 注意和
    // std::vector<char *> roster1 = {"张三", "李四"};
    // std::list<char *> roster2 = {"张三", "李四"};
    // std::cout << std::equal(roster1.cbegin(), roster1.cend(),
    // roster2.cbegin())
    //          << std::endl;
    // 的区别
}
