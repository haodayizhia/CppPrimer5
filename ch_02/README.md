# Chapter 2. Variables and Basic Types

## Exercise 2.1

> What are the differences between `int`, `long`, `long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?

所占比特数不同，能表示的数据范围也不一样。`int` 最小尺寸16位，`long` 最小32位，`long long` 最小64位比特。

带符号类型可以表示正数、负数或0，无符号类型仅能表示大于等于0的值。

浮点型可表示为单精度、双精度和扩展精度值。`float` 一个字（32比特，7个有效位），`double` 两个字（64比特，16个有效位）,`long double` 3个字或4个字。

## Exercise 2.2

> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

浮点型，本金和付款位数较多，选用double，利率可以使用float。

## Exercise 2.3

> What output will the following code produce?

```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出：

```
32 4294967264 32 -32 0 0
```

## Exercise 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

略。

## Exercise 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
>
> - (a) 'a', L'a', "a", L"a"
> - (b) 10, 10u, 10L, 10uL, 012, 0xC
> - (c) 3.14, 3.14f, 3.14L
> - (d) 10, 10u, 10., 10e-2

(a) `char` 型字面值常量，`wchar_t` 宽字符型字面值，字符串字面值，宽字符型字符串字面值。

(b) 十进制整型字面值，十进制无符号整型字面值，十进制长整型字面值，十进制无符号长整型字面值，八进制整型字面值，十六进制整型字面值。

(c) 双精度浮点型字面值，单精度浮点型字面值，扩展精度浮点型字面值。

(d) 十进制整型字面值，十进制无符号整型字面值，双精度浮点型字面值，双精度浮点型字面值。

## Exercise 2.6

> What, if any, are the differences between the following definitions:

```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行为十进制，第二行八进制且09不合法。

## Exercise 2.7

> What values do these literals represent? What type does each have?
>
> - (a) "Who goes with F\145rgus?\012"
> - (b) 3.14e1L
> - (c) 1024f
> - (d) 3.14L

(a) Who goes with Fergus?（换行）

(b) 31.4，扩展精度浮点型字面值。

(c) 1024，单精度浮点型字面值。

(d) 3.14，扩展精度浮点型字面值。

## Exercise 2.8

> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "2M\n" << std::endl;
    std::cout << "2\t\115\12" << std::endl;
    return 0;
}
```

## Exercise 2.9

> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
> - (a) `std::cin >> int input_value;`
> - (b) `int i = { 3.14 };`
> - (c) `double salary = wage = 9999.99;`
> - (d) `int i = 3.14;`

(a) expected primary-expression before 'int'.

```cpp
int input_value;
std::cin >> input_value;
```

(b) narrowing conversion of '3.1400000000000001e+0' from 'double' to 'int' inside { } [-Wnarrowing]. 类型转换未执行，存在丢失信息的危险。

```cpp
double i = { 3.14 };
```

(c) wage未声明。

```cpp
double wage;
double salary = wage = 9999.99
```

(d) 合法，但是会丢失部分值。

## Exercise 2.10

> What are the initial values, if any, of each of the following variables?
>
> ```cpp
> std::string global_str;
> int global_int;
> int main()
> {
>     int local_int;
>     std::string local_str;
> }
> ```

- `global_str` 是一个全局变量，为空字符串。
- `gobal_int` 是一个全局变量，为0。
- `local_int` 在函数体内部，内置类型不被初始化，值未定义。
- `local_str` 在函数体内部，但是初始值由类定义，所以为空字符串。

## Exercise 2.11

> Explain whether each of the following is a declaration or a definition:
> - (a) `extern int ix = 1024;`
> - (b) `int iy;`
> - (c) `extern int iz;`

- (a)：定义。
- (b)：定义。
- (c)：声明。

## Exercise 2.12

> Which, if any, of the following names are invalid?
> - (a) `int double = 3.14;`
> - (b) `int _;`
> - (c) `int catch-22;`
> - (d) `int 1_or_2 = 1;`
> - (e) `double Double = 3.14;`
