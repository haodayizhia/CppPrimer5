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
！[]
