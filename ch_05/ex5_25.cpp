#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int i, j;
    while (cin >> i >> j) {
        try {
            if (j == 0) throw runtime_error("divisor is 0");
            cout << static_cast<double>(i) / j << endl;
        } catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "continue?" << endl;
            char c;
            cin >> c;
            if (c != 'y') break;
        }
    }
    return 0;
}
