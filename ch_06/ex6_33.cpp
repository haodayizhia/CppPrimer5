void print(const vector<int> &ivec) {
    static size_t i = 0;
    if (i < ivec.size()) {
        cout << ivec[i++] << ' ';
        print(ivec);
    } else
        cout << endl;
}

// 用迭代器更好
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using Iter = vector<int>::iterator;

void print(Iter beg, Iter end)
{
    if (beg != end) {
        cout << *beg << " ";
        print(std::next(beg), end);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec.begin(), vec.end());
}
