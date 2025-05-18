#include "ex12_30.h"

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: " << std::endl;
        std::string queryWord;
        if (!(std::cin >> queryWord) || queryWord == "q")
            break;
        print(std::cout, tq.query(queryWord)) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::ifstream input("1.txt");
    runQueries(input);
    return 0;
}
