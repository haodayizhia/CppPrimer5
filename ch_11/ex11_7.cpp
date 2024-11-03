#include <iostream>
#include <map>
#include <set>

int main(int argc, char *argv[]) {
    std::map<std::string, std::set<std::string>> families;
    families["liu"] = std::set<std::string>{"liu"};
    families["liu"].insert("liao");
    for (const auto &f : families) {
        std::cout << f.first << ":";
        for (const auto &kids : f.second) std::cout << " " << kids;
        std::cout << std::endl;
    }
}
