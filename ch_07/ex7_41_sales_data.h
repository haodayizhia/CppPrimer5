class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

   public:
    // 默认构造函数
    Sales_data(const std::string &s = "") : bookNo(s) {
        std::cout << "Sales_data(const std::string &s = \"\")" << std::endl;
    }
    Sales_data(const std::string &s, unsigned n, double p) : Sales_data(s) {
        units_sold = n, revenue = p * n;
        std::cout << "Sales_data(const std::string &s, unsigned n, double p)"
                  << std::endl;
    }
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;

   private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
