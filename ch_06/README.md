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

## Exercise 6.15

>why is `s` a reference to const but `occurs` is a plain reference?

因为 `s` 的值不应该被改变，而 `occurs` 是额外的引用实参，用来保存字符出现的次数。

>Why are these parameters references, but the char parameter `c` is not?

`c` 为单个字符，用值传递就可以。

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` 可以为普通引用，但用常量引用更安全，如果 `occurs` 为常量引用无法传递次数。

## Exercise 6.16

不能把const对象、字面值常量或者需要类型转换的对象传递给普通的引用形参，无法在形参定义为常量引用的函数中正常使用。

```cpp
bool is_empty(const string& s) { return s.empty(); }
```

## [Exercise 6.17](ex6_17.cpp)

不同，前者不需要改变实参，后者需要。
