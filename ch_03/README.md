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
