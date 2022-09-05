# Chapter 3. Strings, Vectors, and Arrays

## Exercise 3.1 : [ex3_1](ex3_1.cpp)

## Exercise 3.2 : [ex3_2](ex3_2.cpp)

## Exercise 3.3

>Explain how whitespace characters are handled in the string input operator and in the `getline` function.

string读入时忽略开头的空白，从第一个真正的字符读起，到空白字符结束。
getline读入包括空白字符在内的字符，到换行符结束。

## Exercise 3.4 : [part1](ex3_04a.cpp) | [part2](ex3_04b.cpp)

## Exercise 3.5 : [part1](ex3_05a.cpp) | [part2](ex3_05b.cpp)

## [Exercise 3.6](ex3_06.cpp)

## Exercise 3.7

> What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

没有区别，推断出来也是 `char` 类型。

## [Exercise 3.8](ex3_08.cpp)

范围for更好，使用简便，不用担心使用下标超出范围。

## Exercise 3.9

>What does the following program do? Is it valid? If not, why not?

```cpp
string s;
cout << s[0] << endl;
```

不合法，s为空，s[0]的结果未定义。

## [Exercise 3.10](ex3_10.cpp)

## Exercise 3.11

>Is the following range for legal? If so, what is the type of c?

```cpp
const string s = "Keep out!";
for (auto &c : s){/*... */}
```
c的类型为 `const char &` ，如果改变了c的值则不合法。

## Exercise 3.12

>Which, if any, of the following vector definitions are in error?
For those that are legal, explain what the definition does.
For those that are not legal, explain why they are illegal.

```cpp
vector<vector<int>> ivec;         // 合法(c++11)，旧版用vector<vector<int> > ivec。
vector<string> svec = ivec;       // 不合法，类型不匹配。
vector<string> svec(10, "null");  // 合法，10个值为"null"的string。
```

## Exercise 3.13

>How many elements are there in each of the following vectors? What are the values of the elements?

```cpp
vector<int> v1;         // 空。
vector<int> v2(10);     // 10个0。
vector<int> v3(10, 42); // 10个42。
vector<int> v4{10};     // 1个10。
vector<int> v5{10, 42}; // 10和42。
vector<string> v6{10};  // 10个空。
vector<string> v7{10, "hi"};  // 10个"hi"。
```

## [Exercise 3.14](ex3_14.cpp)

## [Exercise 3.15](ex3_15.cpp)

## [Exercise 3.16](ex3_16.cpp)

## [Exercise 3.17](ex3_17.cpp)

## [Exercise 3.18](ex3_18.cpp)

## [Exercise 3.19](ex3_19.cpp)

第一种最好，理由如下：

- 简洁方便

- 直接构造，不占内存

- 不会溢出

## [Exercise 3.20](ex3_20.cpp)

## [Exercise 3.21](ex3_21.cpp)

## [Exercise 3.22](ex3_22.cpp)

## [Exercise 3.23](ex3_23.cpp)

## [Exercise 3.24](ex3_24.cpp)

## [Exercise 3.25](ex3_25.cpp)

## Exercise 3.26

>In the binary search program on page 112,
why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

迭代器没有定义加法。

## Exercise 3.27

>Assuming txt_size is a function that takes no arguments
and returns an int value, which of the following definitions are illegal?
Explain why.

```cpp
unsigned buf_size = 1024;

int ia[buf_size];   // 非法，数组的维度必须是常数。
int ia[4 * 7 - 14]; // 合法。
int ia[txt_size()]; // 非法。
char st[11] = "fundamental";  // 非法，字符串字面值初始化数组会在尾部加一个空字符，空间不够。
```
## Exercise 3.28

>What are the values in the following arrays?

```cpp
string sa[10];  // 空字符串
int ia[10];     // 函数外默认初始化0

int main() {
  string sa2[10];   // 空字符串
  int ia2[10];      // 未定义
}
```

## Exercise 3.29

>List some of the drawbacks of using an array instead of a vector.

- 初始化和赋值不方便。
- 不够灵活，不能改变大小。
- 没有迭代器，可能超出范围。
- 没有基于迭代器的算法，功能不丰富。

## Exercise 3.30

>Identify the indexing errors in the following code:

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```
数组下标越界。

## [Exercise 3.31](ex3_31.cpp)

## [Exercise 3.32](ex3_32.cpp)

## Exercise 3.33

>What would happen if we did not initialize the scores array in the program on page 104?

值未定义。

## Exercise 3.34

>Given that p1 and p2 point to elements in the same array, what does the following code do?
Are there values of p1 or p2 that make this code illegal?

```cpp
p1 += p2 - p1;
```
让p1等于p2，合法。

## [Exercise 3.35](ex3_35.cpp)

## [Exercise 3.36](ex3_36.cpp)

## Exercise 3.37

>What does the following program do?

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```
定义一个C风格字符串 `ca` ，把 `ca` 首元素指针赋值给 `cp` ，打印数组所有非空字符。

## Exercise 3.38

>In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

指针相减可以得到它们之间要移动多少，而相加的值不能用来访问指定的对象，所以没有意义。

## [Exercise 3.39](ex3_39.cpp)

## [Exercise 3.40](ex3_40.cpp)

## [Exercise 3.41](ex3_41.cpp)

## [Exercise 3.42](ex3_42.cpp)

## [Exercise 3.43](ex3_43.cpp)

## [Exercise 3.44](ex3_44.cpp)

## [Exercise 3.45](ex3_45.cpp)
