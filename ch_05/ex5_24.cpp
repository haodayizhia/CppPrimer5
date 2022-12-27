#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int i, j;
    cin >> i >> j;
    if (j == 0) throw runtime_error("divisor is 0");
    cout << static_cast<double>(i) / j << endl;
    return 0;
}
