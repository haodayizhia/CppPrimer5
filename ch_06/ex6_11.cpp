#include <iostream>

using namespace std;

void reset(int &i) {
    i = 0;
}

int main(int argc, char *argv[]) {
    int j = 42;
    reset(j);
    cout << j << endl;
    return 0;
}
