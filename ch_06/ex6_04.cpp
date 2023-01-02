#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
    int ret = 1;
    while (val > 1) ret *= val--;
    return ret;
}

void factorial_with_interacts()
{
    for (int val = 0; cout << "Enter a number within [0, 13): ", cin >> val;) {
        if (val < 0 || val > 12) continue;
        cout << val << "! =" << fact(val) << endl;
    }
}

int main()
{
    factorial_with_interacts();
}
