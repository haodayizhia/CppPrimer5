#include <iostream>
#include <vector>

using namespace std;

void print(const char p[]) {
    if (p)
        while (*p) cout << *p++;
    cout << endl;
}

void print(const int *beg, const int *end) {
    while (beg != end) cout << *beg++ << ' ';
    cout << endl;
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i < size; ++i) cout << *ia++ << ' ';
    cout << endl;
}

template <typename T, unsigned U>
void print(const T (&arr)[U]) {
    for (auto i : arr) cout << i << ' ';
    cout << endl;
}

int main(int argc, char *argv[]) {
    int ivec[3] = {1, 2, 3};
    print(ivec, 3);
    return 0;
}
