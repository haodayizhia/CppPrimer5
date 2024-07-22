// Type your code here, or load an example.
#include <array>
#include <iostream>
#include <string>
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
    std::string delimiters = " ,/";
    auto delm1 = s.find_first_of(delimiters);
    std::string month_str = s.substr(0, delm1);
    if (std::isdigit(month_str.at(0)))
        month = stoi(month_str);
    else {
        for (size_t i = 0; i != 12; ++i)
            if (month_str.find(months[i])!=std::string::npos) month = i + 1;
    }
    auto delm2 = s.find_first_of(delimiters, delm1 + 1);
    day = stoi(s.substr(delm1 + 1, delm2 - delm1));
    year = stoi(s.substr(delm2 + 1));
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
