#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

class QueryResult;

class TextQuery {
   public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

   private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending) {
    return ctr > 1 ? word + ending : word;
}

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

   public:
    using line_no = TextQuery::line_no;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f) {};

    std::set<line_no>::iterator begin() const { return lines->begin(); };
    std::set<line_no>::iterator end() const { return lines->end(); };
    std::weak_ptr<std::vector<std::string>> getfile() const { return file; }

   private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "times", "s") << std::endl;
    for (auto num : *(qr.lines))
        os << "\t" << "(line " << num + 1 << ") " << *(qr.file->begin() + num)
           << std::endl;
    return os;
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata =
        std::make_shared<std::set<line_no>>();
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
