#include <algorithm>
#include <iostream>
#include <vector>

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
       << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main(int argc, char *argv[]) {
    Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
        d4("CppCore"), d5("AwesomeCPP");
    std::vector<Sales_data> v{d1, d2, d3, d4, d5};
    std::sort(v.begin(), v.end(),
              [](const Sales_data &s1, const Sales_data &s2) {
                  return s1.isbn() < s2.isbn();
              });
    for (const auto &element : v) std::cout << element.isbn() << " ";
    std::cout << std::endl;
}
