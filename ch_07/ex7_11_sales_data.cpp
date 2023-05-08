#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Sales_data item1;
    print(cout, item1) << endl;
    Sales_data item2("congqianyouzuolingjianshan");
    print(cout, item2) << endl;
    Sales_data item3("congqianyouzuolingjianshan", 1, 40);
    print(cout, item3) << endl;
    Sales_data item4(cin);
    print(cout, item4) << endl;
    return 0;
}
