#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
    std::ifstream infile("1.txt");
    std::vector<std::string> textData;
    std::map<std::string, std::set<int>> index;
    std::string lineText;
    int lineNum = 1;
    while (std::getline(infile, lineText)) {
        textData.push_back(lineText);
        std::istringstream lineStream(lineText);
        std::string word;
        while (lineStream >> word) {
            index[word].insert(lineNum);
        }
        ++lineNum;
    }
    while (true) {
        std::cout << "enter word to look for, or q to quit: " << std::endl;
        std::string queryWord;
        if (!(std::cin >> queryWord) || queryWord == "q") break;
        std::cout << queryWord << " occurs " << index[queryWord].size()
                  << " times " << std::endl;
        for (const auto &i : index[queryWord])
            std::cout << "\t" << "(line " << i << ") " << textData[i - 1]
                      << std::endl;
    }
    return 0;
}
