#include <iostream>
#include <string>
#include <vector>

// 使用迭代器版本
std::string sub1(std::string s, std::string &oldVal, std::string &newVal) {
    auto it = s.begin();
    while (it != s.end() - oldVal.size() + 1) {
        size_t i = 0;
        for (; i < oldVal.size() && *(it + i) == oldVal.at(i); ++i) {
        }
        if (i == oldVal.size()) {
            it = s.erase(it, it + oldVal.size());
            for (size_t j = 0; j < newVal.size(); ++j)
                it = s.insert(it, newVal.at(j)) + 1;
        } else
            ++it;
    }
    return s;
}

// 使用下标版本
std::string sub2(std::string s, std::string &oldVal, std::string &newVal) {
    for (size_t p = 0; p != s.size() - oldVal.size() + 1;) {
        size_t i = 0;
        for (; i < oldVal.size() && s.at(p + i) == oldVal.at(i); ++i) {
        }
        if (i == oldVal.size()) {
            s.erase(p, oldVal.size());
            s.insert(p, newVal);
            p += newVal.size();
        } else
            ++p;
    }
    return s;
}

int main() {
    std::string s = "tho i want money, i thot i can get it thru steal";
    std::string oldVal = "tho";
    std::string newVal = "though";
    std::cout << sub2(s, oldVal, newVal) << std::endl;
    return 0;
}
