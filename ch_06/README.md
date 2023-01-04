# Chapter 6. Functions

## Exercise 6.1

形参是定义在函数内的变量，实参定义在函数外，用来初始化形参。

## Exercise 6.2

```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

## Exercise 6.3

```cpp
#include <iostream>

int fact(int val)
{
    if (val == 0 || val == 1) return 1;
    else return val * fact(val-1);
}

int main()
{
    int j = fact(5);  // j equals 120, i.e., the result of fact(5)
    std::cout << "5! is " << j << std::endl;
    return 0;
}
```

## [Exercise 6.4](ex6_04.cpp)

## Exercise 6.5

```cpp
template <typename T>
T abs(T i) {
    return i > 0 ? i : -i;
}
```

## Exercise 6.6

**局部变量**: 定义在块作用域中;

**形参**: 在函数参数列表中声明，作用域在函数内；

**局部静态变量**: 在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才销毁，在此期间即使对象所在的函数执行结束也不会对它有影响。
```cpp
#include <iostream>

using namespace std;

size_t test(int a) { return a >= 0 ? a : -a; }

int main(int argc, char *argv[]) {
    static int a = -1;
    size_t b = a;
    cout << a << ' ' << b << endl;
    return 0;
}
```

## Exercise 6.7

```cpp
int test() {
    static int a = 0;
    return a++;
}
```

## [Exercise 6.8](Chapter6.h)

## Exercise 6.9 [fact.cc](fact.cc) | [factMain.cc](factMain.cc)

## [Exercise 6.10](ex6_10.cpp)

## [Exercise 6.11](ex6_11.cpp)

## [Exercise 6.12](ex6_12.cpp)

## Exercise 6.13

`void f(T)` 值传递， **对形参的改变不影响实参的值**。
`void f(T&)` 引用传递， 形参绑定实参。

## Exercise 6.14

形参应该是引用：

```cpp
void example1(ostream& out) { out << "pass by reference" << endl; }
```

形参不能是引用：

```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (; begin != end; ++begin)
                std::cout << *begin << std::endl;
}
```
