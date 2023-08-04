#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main(int argc, char *argv[]) {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::ifstream in("a.txt");
    while (getline(in, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word) info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }
    return 0;
}
