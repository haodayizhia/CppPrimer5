#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult() = default;
    QueryResult(std::string queryWord, std::shared_ptr<std::vector<std::string>> d,
                std::shared_ptr<std::set<int>> l)
        : word(queryWord), textData(d), lines(l), count(l->size()) {};

private:
    std::string word;
    std::shared_ptr<std::vector<std::string>> textData;
    std::shared_ptr<std::set<int>> lines;
    int count;
};

std::ostream &print(std::ostream &out, const QueryResult &res)
{
    out << res.word << " occurs " << res.count << " times " << std::endl;
    for (const auto &i : *(res.lines))
        out << "\t" << "(line " << i << ") " << (*res.textData)[i - 1] << std::endl;
    return out;
}

class TextQuery
{
public:
    TextQuery() = default;
    TextQuery(std::ifstream &);
    QueryResult query(std::string &);

private:
    std::shared_ptr<std::vector<std::string>> textData;
    std::map<std::string, std::shared_ptr<std::set<int>>> index;
};

TextQuery::TextQuery(std::ifstream &infile)
{
    std::string lineText;
    int lineNum = 1;
    textData = std::make_shared<std::vector<std::string>>();
    while (std::getline(infile, lineText))
    {
        textData->push_back(lineText);
        std::istringstream lineStream(lineText);
        std::string word;
        while (lineStream >> word)
        {
            if (!index[word])
                index[word] = std::make_shared<std::set<int>>();
            index[word]->insert(lineNum);
        }
        ++lineNum;
    }
}

QueryResult TextQuery::query(std::string &word)
{
    static std::shared_ptr<std::set<int>> nodata = std::make_shared<std::set<int>>();
    auto it = index.find(word);
    if (it == index.end())
        return QueryResult(word, textData, nodata);
    else
        return QueryResult(word, textData, it->second);
}
