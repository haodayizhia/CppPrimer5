#include <algorithm>
#include <iostream>
#include <map>
#include <set>

void ex11_20(std::map<std::string, size_t> &word_count,
             std::set<std::string> &exclude)
{
    std::string word;
    while (std::cin >> word)
        if (exclude.find(word) == exclude.end())
        {
            // 下标操作更简单, 可以直接完成插入或计数器+1
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
                ++ret.first->second;
        };
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
}

int main(int argc, char *argv[])
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "an", "a"};
    ex11_20(word_count, exclude);
}
