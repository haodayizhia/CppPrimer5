#include <iostream>
#include <vector>

using namespace std;

void f() { cout << "f()" << endl; }
void f(int) { cout << "f(int)" << endl; }
void f(int, int) { cout << "f(int,int)" << endl; }
void f(double, double = 3.14) { cout << "f(double, double = 3.14)" << endl; }
int main() {
    f();
    f(1);
    f(1, 1);
    f(1.0, 1.0);
}
