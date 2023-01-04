#include <iostream>

using namespace std;

void exchange(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    int i = 1, j = 2;
    exchange(&i, &j);
    cout << i << ' ' << j << endl;
    return 0;
}
