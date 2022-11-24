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

## [Exercise 5.9](ex5_09.cpp)

## [Exercise 5.10](ex5_10.cpp)

## [Exercise 5.11](ex5_11.cpp)

## [Exercise 5.12](ex5_12.cpp)

## Exercise 5.13

>Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

```cpp
(a) // 缺少break
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default : iouCnt++; break;
    }
(b) // 错误，控制流绕过一个显式初始化的变量
    unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
(c) // 一个case只能表示一种情形
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
(d) // case标签必须是整型常量表达式
    const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```
