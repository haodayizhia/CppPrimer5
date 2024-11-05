#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::pair<std::string, int>> pvec;
    std::string word;
    int count;
    while (std::cin >> word >> count)
        pvec.push_back({word, count});
    //! ex11_13
    // pvec.push_back(std::pair<std::string, int>(word, count));
    // pvec.push_back(std::make_pair(word, count));
    // pvec.emplace_back(word, count);
    for (const auto i : pvec)
        std::cout << i.first << ' ' << i.second << std::endl;
    return 0;
}
