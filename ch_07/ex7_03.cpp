#include <iostream>

using namespace std;

struct Sales_data {
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main(int argc, char *argv[]) {
    Sales_data total;
    double price = 0;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = price * total.units_sold;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * trans.units_sold;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                cout << total.isbn() << ' ' << total.units_sold << ' '
                     << total.revenue << ' '
                     << (total.units_sold == 0
                             ? 0
                             : total.revenue / total.units_sold)
                     << endl;
                total = trans;
            }
        }
        cout << total.isbn() << ' ' << total.units_sold << ' ' << total.revenue
             << ' '
             << (total.units_sold == 0 ? 0 : total.revenue / total.units_sold)
             << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}
