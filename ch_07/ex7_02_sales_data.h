using namespace std;

#include <iostream>

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    string isbn() { return bookNo; }
    Sales_data& combine(Sales_data& s) {
        units_sold += s.units_sold;
        revenue += s.revenue;
        return *this;
    }
};
Sales_data add(Sales_data& s1, Sales_data& s2) {
    Sales_data res;
    res.bookNo = s1.bookNo;
    res.units_sold = s1.units_sold + s2.units_sold;
    res.revenue = s1.revenue + s2.revenue;
    return res;
}
bool read(istream& in, Sales_data& s) {
    if (in >> s.bookNo >> s.units_sold >> s.revenue)
        return 1;
    else
        return 0;
}
void print(ostream& out, Sales_data& s) {
    out << s.bookNo << ' ' << s.units_sold << ' ' << s.revenue << endl;
}
