# Chapter 5. Statements

## Exercise 5.1

>What is a null statement? When might you use a null statement?

空语句是只有分号的语句，如：

```cpp
; // 空语句
```

如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，如:

```cpp
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // 空语句
```
    
## Exercise 5.2

>What is a block? When might you might use a block?

块是指用花括号括起来的（可能为空的）语句和声明的序列，也称复合语句。

如：

```cpp
while (val <= 10)
{
    sum += val;
    ++val;
}
```

## Exercise 5.3

>Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
```

降低了可读性。

## Exercise 5.4

>Explain each of the following examples, and correct any problems you detect.
> ```cpp
> - (a) while (string::iterator iter != s.end()) { /* . . . */ }
> - (b) while (bool status = find(word)) { /* . . . */ }
>         if (!status) { /* . . . */ }
> ```

(a) 迭代器iter没有初始化为空。

```cpp
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
```

(b) if语句在循环体外，超出status变量的作用范围。

```cpp
bool status;
while ((status = find(word))) {/* ... */}
if (!status) {/* ... */}
```
## [Exercise 5.5](ex5_05.cpp)

## [Exercise 5.6](ex5_06.cpp)

## Exercise 5.7

>Correct the errors in each of the following code fragments:

```cpp
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

```cpp
(a) if (ival1 != ival2) ival1 = ival2; // 缺少分号
    else ival1 = ival2 = 0;
(b) if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
(c) int val;
    if (ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
(d) if (ival == 0)
    ival = get_value();
```

## Exercise 5.8

>What is a “dangling else”? How are else clauses resolved in C++?

悬垂else指if语句嵌套时，当if多于else的情况下else与if的匹配问题。在c++中，else与离它最近的尚未匹配的if匹配。
