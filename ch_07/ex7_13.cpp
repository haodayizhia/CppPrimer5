int main(int argc, char *argv[]) {
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        while (cin) {
            Sales_data trans(cin);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
