#include "ex7_21_sales_data.h"

int main(int argc, char *argv[]) {
    std::cout << "Exercise VERSION " << Exercise_VERSION_MAJOR << '.'
              << Exercise_VERSION_MINOR << std::endl;
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    Sales_data i;
    while (read(in, i)) print(out, i) << std::endl;
    return 0;
}
