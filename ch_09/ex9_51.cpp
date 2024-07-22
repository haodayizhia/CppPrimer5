// Type your code here, or load an example.
#include <array>
#include <iostream>
#include <string>
#include <vector>

class date {
   public:
    explicit date(std::string);
    inline void print();

   private:
    unsigned month;
    unsigned day;
    unsigned year;
    std::array<std::string, 12> months = {"Jan", "Feb", "Mar", "Apr",
                                          "May", "Jun", "Jul", "Aug",
                                          "Sep", "Oct", "Nov", "Dec"};
};
date::date(std::string s) {
    std::vector<unsigned int> uvec;
    size_t pos = 0;
    while (pos != s.size()) {
        if (isalnum(s[pos]) || isdigit(s[pos])) {
            uvec.push_back(pos);
            size_t j = pos + 1;
            while (j != s.size() && (isalnum(s[j]) || isdigit(s[j]))) ++j;
            pos = j;
            uvec.push_back(pos);
        } else
            ++pos;
    }
    std::string month_str = s.substr(uvec[0], uvec[1] - uvec[0]);
    if (std::isdigit(month_str.at(0)))
        month = stoi(month_str);
    else {
        for (size_t i = 0; i != 12; ++i)
            if (month_str.find(months[i]) != std::string::npos) month = i + 1;
    }
    day = stoi(s.substr(uvec[2], uvec[3] - uvec[2]));
    year = stoi(s.substr(uvec[4], uvec[5] - uvec[4]));
}
inline void date::print() {
    std::cout << month << ' ' << day << ' ' << year << std::endl;
}

int main(int argc, char* argv[]) {
    date a("1/1/1990");
    date b("January 1, 1900");
    date c("Jan 1 1900");
    a.print();
    b.print();
    c.print();
    return 0;
}
