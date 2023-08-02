#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "ex7_21_sales_data.h"

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2], std::ofstream::out);
    Sales_data i;
    while (read(in, i)) print(out, i) << std::endl;
    return 0;
}
