#include <iostream>
#include <set>

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char *argv[]) {
    std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
        bookstore(compareIsbn);
    return 0;
}
