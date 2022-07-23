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

## Exercise 2.13

> What is the value of j in the following program?
>
> ```cpp
> int i = 42;
> int main()
> {
>     int i = 100;
>     int j = i;
> }
> ```

100

## Exercise 2.14

> Is the following program legal? If so, what values are printed?

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

合法，100，45.

## Exercise 2.14

> Which of the following definitions, if any, are invalid? Why?
> - (a) `int ival = 1.01;`
> - (b) `int &rval1 = 1.01;`
> - (c) `int &rval2 = ival;`
> - (d) `int &rval3;`

- (a): 合法，但丢失部分值。
- (b): 不合法，引用的初始值必须是一个对象。
- (c): 合法。
- (d): 不合法，引用必须初始化。

## Exercise 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
>
> ```cpp
> int i = 0, &r1 = i;
> double d = 0, &r2 = d;
> ```
>
> - (a) r2 = 3.14159;
> - (b) r2 = r1;
> - (c) i = r2;
> - (d) r1 = d;

- (a): 合法，d等于3.14159。
- (b): 合法，类型自动转换。
- (c): 合法，但是丢失部分值。
- (d): 合法，但是丢失部分值。

## Exercise 2.17

> What does the following code print?
>
> ```cpp
> int i, &ri = i;
> i = 5; ri = 10;
> std::cout << i << " " << ri << std::endl;
> ```

10, 10

## Exercise 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```cpp
int a = 0, *p = nullptr;

// 改变指针的值
p = &a;
// 改变指针所指对象的值
*p = 1;
```
## Exercise 2.19

> Explain the key differences between pointers and references.

指针是一个对象，引用不是一个对象只是别名，所以引用必须初始化而且不能赋值。

## Exercise 2.20

> What does the following program do?
>
> ```cpp
> int i = 42;
> int *p1 = &i; *p1 = *p1 * *p1;
> ```

`p1`指向`i`，等于42^2=1764。

## Exercise 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
>
> ```cpp
> int i = 0;
> ```
>
> - (a) `double* dp = &i;`
> - (b) `int *ip = i;`
> - (c) `int *p = &i;`

- (a): 非法，类型不匹配。
- (b): 非法，不能把变量直接赋给指针。
- (c): 合法。

## Exercise 2.22

> Assuming p is a pointer to int, explain the following code:
>
> ```cpp
> if (p) // p的值为0？
> if (*p) // p指向的值为0？
> ```

## Exercise 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

不能，不知道`p`的值是否指向需要的对象。

## Exercise 2.24

> Why is the initialization of `p` legal but that of `lp` illegal?
>
> ```cpp
> int i = 42;
> void *p = &i;
> long *lp = &i;
> ```

指针指向的类型要和赋值的类型匹配，`void` 指针可以存放任意对象的地址。

## Exercise 2.25

> Determine the types and values of each of the following variables.
>
> - (a) `int* ip, i, &r = i;`
> - (b) `int i, *ip = 0;`
> - (c) `int* ip, ip2;`

- (a): ip是一个 `int` 型的指针，`i` 是一个`int` 类型，`r` 是一个 `int` 类型的引用。
- (b): `i` 是一个`int` 类型，`ip` 是一个 `int` 类型的空指针。
- (c): ip是一个 `int` 型的指针，`ip2` 是一个`int` 类型。

## Exercise 2.26

> Which of the following are legal? For those that are illegal, explain why.
>
> ```cpp
> (a) const int buf;      // 错误，未经初始化。
> (b) int cnt = 0;        // 合法。
> (c) const int sz = cnt; // 合法。
> (d) ++cnt;              // 合法
>     ++sz;               // 不合法，常量不能改变。
> ```

## Exercise 2.27

> Which of the following initializations are legal? Explain why.
>
> ```cpp
> (a) int i = -1, &r = 0;         // 不合法，r必须绑定一个对象。
> (b) int *const p2 = &i2;        // 不合法，p2是一个普通指针。
> (c) const int i = -1, &r = 0;   // 合法。
> (d) const int *const p3 = &i2;  // 合法。
> (e) const int *p1 = &i2;        // 合法。
> (f) const int &const r2;        // 不合法，引用必须初始化。
> (g) const int i2 = i, &r = i;   // 合法。
> ```

## Exercise 2.28

> Explain the following definitions. Identify any that are illegal.
>
> ```cpp
> (a) int i, *const cp;       // 不合法，常量指针必须初始化。
> (b) int *p1, *const p2;     // 不合法。
> (c) const int ic, &r = ic;  // 不合法，常量必须初始化。
> (d) const int *const p3;    // 不合法。
> (e) const int *p;           // 合法。
> ```

## Exercise 2.29

> Using the variables in the previous ## Exercise, which of the following assignments are legal? Explain why.
>
> ```cpp
> (a) i = ic;     // 合法。
> (b) p1 = p3;    // 不合法，p3指向常量。
> (c) p1 = &ic;   // 不合法，ic是一个常量。
> (d) p3 = &ic;   // 不合法，p3是常量指针。
> (e) p2 = p1;    // 不合法。
> (f) ic = *p3;   // 不合法。
> ```

## Exercise 2.29

> Using the variables in the previous ## Exercise, which of the following assignments are legal? Explain why.
>
> ```cpp
> (a) i = ic;     // 合法。
> (b) p1 = p3;    // 不合法，p3指向常量而p1指向变量。
> (c) p1 = &ic;   // 不合法。
> (d) p3 = &ic;   // 合法。
> (e) p2 = p1;    // 不合法，p2是一个常量指针。
> (f) ic = *p3;   // 不合法，ic是一个常量。
> ```
