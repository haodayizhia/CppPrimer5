#include <iostream>
#include <vector>

//#define NDEBUG

using namespace std;

void print(vector<int> ivec) {
#ifndef NDEBUG
    cout << "size:" << ivec.size() << ' ';
#endif
    if (!ivec.empty()) {
        cout << ivec[0] << endl;
        print(vector<int>(next(ivec.begin()), ivec.end()));
    }
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec);
}
