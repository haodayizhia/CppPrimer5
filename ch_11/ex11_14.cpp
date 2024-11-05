#include <iostream>
#include <map>
#include <set>
#include <vector>

int main(int argc, char *argv[])
{
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
    std::string lastName, firstName, birthday;
    std::cout << "input last name, first name and birthday: " << std::endl;
    if (std::cin >> lastName)
    {
        while (std::cin >> firstName >> birthday)
            families[lastName].push_back({firstName, birthday});
    }
    for (const auto &i : families)
    {
        std::cout << i.first << ': ';
        for (const auto &j : i.second)
            std::cout << j.first << ' ' << j.second << ' ';
        std::cout << std::endl;
    }
}
