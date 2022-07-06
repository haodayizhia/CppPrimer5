# Chapter 1. Getting started

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.
> 
- Windows

![windows](https://github.com/haodayizhia/CppPrimer5/blob/0f23e193d707cc0a79cdf8363de7c24e87e33115/ch_01/1_1.png)

## Exercise 1.2

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

-Windows

![Windows](https://github.com/haodayizhia/CppPrimer5/blob/0f23e193d707cc0a79cdf8363de7c24e87e33115/ch_01/1_2.png)

## Exercise 1.3

> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
	std::cout << "Hello, World." << std::endl;
	return 0;
}
```

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
	return 0;
}
```

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

## Exercise 1.6

> Explain whether the following program fragment is legal.

不合法，后面的```<<```运算符没有运算对象。应该去掉换行处的分号。

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
    /*注释
    /*注释
     */
    *注释已经结束
    */
    int a = 1;
    return 0;
}
```
错误信息：
![ex1_7](https://github.com/haodayizhia/CppPrimer5/blob/eef6f8b281bc7f7374a90d34f9960be3d8f48b2f/ch_01/ex1_7.png)

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

编译结果：
![ex1_8](https://github.com/haodayizhia/CppPrimer5/blob/843211d1be98ea71c7461bb3eece8dfc8de13ecb/ch_01/ex1_8.png)
改正：
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```
输出：
```
/**/ */ /*
```

## [Exerciese 1.9](ex1_9.cpp)

## [Exerciese 1.10](ex1_10.cpp)

## [Exerciese 1.11](ex1_11.cpp)

## Exercise 1.12

> What does the following for loop do? What is the final value of sum?

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

从-100加到100，结果等于0

## Exercise 1.13

> Rewrite the exercises from 1.4.1 (p. 13) using for loops.

**Ex1.9**:

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << sum << std::endl;
	return 0;
}
```

**Ex1.10**

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0;
	for (int i = 10; i >= 0; --i)
		std::cout << i << ' ';
	std::cout << std::endl;
	return 0;
}
```

**Ex1.11**

```cpp
#include <iostream>
int main(int argc, char *argv[])
{
	int num1, num2, k;
	std::cin >> num1 >> num2;
	k = abs(num1 - num2);
	for (int i = 0; i <= k; ++i)
	{
		std::cout << num1 << ' ';
		num1 += (num1 < num2 ? 1 : -1);
	}
	return 0;
}
```
## Exercise 1.14

> Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

- while的特点
	- 判断的条件明显
	- 不需要计算多少步
- for的特点
	- 判断更为简洁
	- 步数清晰

## Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

略

## Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from cin.

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0, value = 0;
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is " << sum << std::endl;
	return 0;
}
```
