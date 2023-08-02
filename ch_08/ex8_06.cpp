#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "ex7_21_sales_data.h"

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    Sales_data i;
    while (read(in, i)) print(std::cout, i) << std::endl;
    return 0;
}
