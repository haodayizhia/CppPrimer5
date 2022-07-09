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
## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

如果全部相等那么程序一直处于输入状态，如果不相等输入一个显示一个。

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![ex1_18](https://github.com/haodayizhia/CppPrimer5/blob/e88ca645e53638b8228844447d442b5add2be9d5/ch_01/ex1_18.png)

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

见 [ex1_11.cpp](https://github.com/haodayizhia/CppPrimer5/blob/6a3ea9a5cf1732e1310c3ce4b9cd65fccbd94d02/ch_01/ex1_11.cpp)

## Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
	Sales_item book;
	while (std::cin >> book)
		std::cout << book << std::endl;
	return 0;
}
```
结果

![ex1_20](https://github.com/haodayizhia/CppPrimer5/blob/e60c14c2fb0ad25c5bd26bae3ca7443f16e7a7a8/ch_01/ex1_20.png)

## Exercise 1.21

> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}
}
```

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
	Sales_item curritem, item;
	if (std::cin >> curritem)
	{
		while (std::cin >> item)
		{
			if (curritem.isbn() == item.isbn())
				curritem += item;
			else
			{
				std::cout << curritem << std::endl;
				curritem = item;
			}
		}
		std::cout << curritem << std::endl;
	}
	else
		std::cerr << "No data?" << std::endl;
	return 0;
}
```

## Exercise 1.23

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
	Sales_item curritem, item;
	int cnt = 1;
	if (std::cin >> curritem)
	{
		while (std::cin >> item)
		{
			if (item.isbn() == curritem.isbn())
				++cnt;
			else
			{
				std::cout << curritem.isbn() << " occurs " << cnt << " times" << std::endl;
				curritem = item;
			}
		}
		std::cout << curritem.isbn() << " occurs " << cnt << " times" << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Nodata?" << std::endl;
		return -1;
	}
}
```

## Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

重定向输入infile文件

![ex1_24](https://github.com/haodayizhia/CppPrimer5/blob/2e4788f378ccb6bc9179a07f6ebfc956869ead97/ch_01/ex1_24.png)
