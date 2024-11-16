#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>

void wordCounting(std::unordered_map<std::string, size_t> &word_count,
                  std::set<std::string> &exclude) {
    std::string word;
    while (std::cin >> word)
        if (exclude.find(word) == exclude.end()) ++word_count[word];
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
}

std::unordered_map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::unordered_map<std::string, std::string> trans_map;
    std::string key, value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    return trans_map;
}
const std::string transform(
    const std::string &s,
    const std::unordered_map<std::string, std::string> &m) {
    auto map_it = m.find(s);
    if (map_it != m.end())
        return map_it->second;
    else
        return s;
}
void word_transform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = buildMap(map_file);
    std::string text;
    while (getline(input, text)) {
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                std::cout << ' ';
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}
int main(int argc, char *argv[]) {
    std::unordered_map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "an", "a"};
    wordCounting(word_count, exclude);

    std::ifstream map_file("word_transformation.txt");
    std::ifstream input("given_to_transform.txt");
    word_transform(map_file, input);
}
