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

## Exercise 6.18

(a)

```cpp
bool compare(const matrix &m1, const matrix &m2);
```

(b)

```cpp
vector<int>::iterator change_val(int, vector<int>::iterator);
```

## Exercise 6.19

(a) 不合法，只有一个参数。
(b) 合法。
(c) 合法。
(d) 合法。

## Exercise 6.20

不需要改变实参的值时尽量用常量引用。函数适用范围变窄，不能传递常量实参或字面值常量，可能改变实参的值。

## [Exercise 6.21](ex6_21.cpp)

## [Exercise 6.22](ex6_22.cpp)

## [Exercise 6.23](ex6_23.cpp)

## Exercise 6.24

数组会转换成指针，当传递的数组维度不是10时仍能传递，但函数运行可能报错。

## [Exercise 6.25 && Exercise 6.26](ex6_25_26.cpp)

## [Exercise 6.27](ex6_27.cpp)

## Exercise 6.28

The type of `elem` in the `for` loop is `const const std::string&`.

## Exercise 6.29

取决于 `initializer_list` 元素的类型，如果复制的开销不大可以不必引用。


## Exercise 6.30

<source>:3:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
<source>:11:33: error: non-void function 'str_subrange' should return a value [-Wreturn-type]
        if (str1[i] != str2[i]) return;
                                ^
1 warning and 1 error generated.

发现了return没有返回值，但没有检测到for循环后没有return。

## Exercise 6.31

引用绑定局部变量。

## Exercise 6.32

合法，将数组 `ia` 赋值0-9。

## [Exercise 6.33](ex6_33.cpp)

## Exercise 6.34

如果 `val` 为负，不断递归至程序占空间耗尽。

## Exercise 6.35

传的是值不是引用。

## Exercise 6.36

```cpp
string (&arrStr())[10];
```

## Exercise 6.37

```cpp
// typedef string arrT[10];
using arrT = string[10];
arrT& arrStr();

auto arrStr() -> string (&)[10];

string arrS[10];
decltype(arrS)& arrStr();
```

都可以。

## Exercise 6.38

```cpp
decltype(odd)& arrPtr(int i) { return (i % 2) ? odd : even; }
```
## Exercise 6.39

(a)非法重载，二义性调用。
(b)非法。
(c)合法重载。

## Exercise 6.40

(b) 一旦某个形参被赋予了默认值，它后面所有形参都必须有默认值。

## Exercise 6.41

(a)非法，缺少实参。
(b)合法。
(c)合法，但是第二个实参会隐式地类型转换。

## [Exercise 6.42](ex6_42.cpp)

## Exercise 6.43

内联函数定义和函数声明都放在头文件中。

## [Exercise 6.44](ex6_44.cpp)

## Exercise 6.45

简单的函数可以声明为内联，复杂的（函数体长、递归函数等）不建议。

## Exercise 6.46

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

原则上不能，constexpr函数的形参和返回值都应该是字面值常量。

参见more discusses: [#22](https://github.com/ReadingLab/Discussion-for-Cpp/issues/22)


## [Exercise 6.47](ex6_47.cpp)

## Exercise 6.48

不合理， `assert` 常用于检查“不能发生”的条件，而正常输入 `EOF` 时会发生。

## Exercise 6.49

候选函数：
重载函数集中的函数成为候选函数，具备两个特征：1、与被调用的函数同名；2、其声明在调用点可见。

可行函数：
候选函数中能被实参调用的函数，具备两个特征：1、形参数量与本次调用提供的实参数量相等；2、每个实参的类型与对应的形参类型相同，或者能转换成形参的类型。

## Exercise 6.50

(a) 不合法，二义性调用。

(b) 匹配 `void f(int)`.

(c) 匹配 `void f(int, int)`。

(d) 匹配 `void f(double, double = 3.14)`。

## [Exercise 6.51](ex6_51.cpp)

## Exercise 6.52

(a) 类型提升，3级。

(b) 类型转换，4级。

## Exercise 6.53

(a)

const版本重载。

(b)

const版本重载。

(c)

非法，一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来。
