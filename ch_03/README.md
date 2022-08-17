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
