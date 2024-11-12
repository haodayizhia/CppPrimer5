#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    // 可以用下标运算符和at函数进行下标操作, 返回mapped_value类型,
    // 如果用at函数访问不存在的元素会抛出一个out_of_range异常
    std::map<int, int> imap = {{1, 1}};
    std::map<int, int>::mapped_type a = imap[1];
    std::map<int, int>::mapped_type b = imap.at(1);
    return 0;
}
