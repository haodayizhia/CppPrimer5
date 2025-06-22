#include <iostream>
#include <string>
#include <vector>

struct X {
    X() : i(0) { std::cout << "X()" << std::endl; };
    X(const X& a) : i(a.i) {
        *p = *a.p;
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator=(const X& a) {
        i = a.i;
        *p = *a.p;
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    int i;
    int* p = new int();
    ~X() {
        delete p;
        std::cout << "~X()" << std::endl;
    }
};

void test1(X) { std::cout << "void test1(X)" << std::endl; }

void test2(X&) { std::cout << "void test2(X&)" << std::endl; }

int main() {
    X x1;
    X x2 = x1;
    test1(x1);
    test2(x2);
    std::vector<X> Xvec = {x1};
}
