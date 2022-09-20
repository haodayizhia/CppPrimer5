# Chapter 4. Expressions

## Exercise 4.1

> What is the value returned by 5 + 10 * 20/2?

105

## Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
>
> ```cpp
> * vec.begin() //=> *(vec.begin())
> * vec.begin() + 1 //=> (*(vec.begin())) + 1
> ```

## Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

我认为可以接受，使用的时候注意就行了。

## Exercise 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
>
> ```cpp
> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
> // parenthesize
> ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
> // 16 + 75 + 0 = 91
> // print: 91
> ```

## Exercise 4.5

> Determine the result of the following expressions.
>
> ```cpp
> -30 * 3 + 21 / 5  // -90+4 = -86
> -30 + 3 * 21 / 5  // -30+63/5 = -30+12 = -18
> 30 / 3 * 21 % 5   // 10*21%5 = 210%5 = 0
> -30 / 3 * 21 % 4  // -10*21%4 = -210%4 = -2
> ```

## Exercise 4.6

> Write an expression to determine whether an int value is even or odd.

```cpp
i % 2 == 0 ? "even" : "odd"
```

## Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.
>
> ```cpp
> short svalue = 32767; ++svalue; // -32768
> unsigned uivalue = 0; --uivalue;  // 4294967295
> unsigned short usvalue = 65535; ++usvalue;  // 0
> ```

溢出：超出类型能表达的范围，产生未定义的结果。

## Exercise 4.8

> Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

from the book:

> The logical `AND` and `OR` operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as **short-circuit evaluation**.

- 逻辑与：先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象为真时才对右侧运算对象求值。
- 逻辑或：先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象为假时才对右侧运算对象求值。
- 相等运算符：当且仅当左右两侧的值相等时为真。

## Exercise 4.9

> Explain the behavior of the condition in the following `if`:
>
> ```cpp
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

cp是一个指向常量字符数组的指针，判断是否为空指针，真。

cp为非空指针，然后判断其指向的字符是否为空，真。

结果为真。

## Exercise 4.10

> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.

```cpp
int i = 0;
while(cin >> i && i != 42)
```

## Exercise 4.11

> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.

```cpp
a > b && b > c && c > d
```

## Exercise 4.12

> Assuming `i`, `j`, and `k` are all ints, explain what `i != j < k` means.

`i != (j < k)` ，把 `j` 和 `k` 比较结果的布尔值与i比较判断是否相等。

## Exercise 4.13

> What are the values of i and d after each assignment?
>
> ```cpp
> int i;   double d;
> d = i = 3.5; // i = 3, d = 3.0
> i = d = 3.5; // d = 3.5, i = 3
> ```

## Exercise 4.14

> Explain what happens in each of the if tests:
>
> ```cpp
> if (42 = i)   // 错误，赋值运算符左侧要为可以改变的左值
> if (i = 42)   // 真
> ```

## Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
>
> ```cpp
> double dval; int ival; int *pi;
> dval = ival = pi = 0;
> // pi为空指针
> // 不存在从指针类型到整型的转换
> // 改正：
> dval = ival = 0;
> pi = 0;
> ```

## Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
>
> ```cpp
> if (p = getPtr() != 0)
> if (i = 1024)
> // 结合顺序和等号作为条件
> // 改正：
> if ((p = getPtr()) != 0)
> if (i == 1024)
> ```

## Exercise 4.17

> Explain the difference between prefix and postfix increment.

前置递增运算符先递增然后将对象本身作为左值返回，后置运算符对象原始值的副本作为右值返回然后递增。

## Exercise 4.18

> What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?

如果没有负值会解引用一个不存在的元素，出现未定义的错误。

## Exercise 4.19

> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
>
> ```cpp
> ptr != 0 && *ptr++  // 如果ptr不为空指针且值不为0，递增ptr，真
> ival++ && ival // 如果ival不为0，递增ival，如果也不为0，真
> vec[ival++] <= vec[ival] // 错误，左侧改变了ival的值，右侧又用到了ival，
> // correct:
> vec[ival] <= vec[ival+1]
> ```

## Exercise 4.20

> Assuming that iter is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
>
> ```cpp
> *iter++;  // 返回*iter，指针递增。
> (*iter)++;  // 不合法，string类型不能++。
> *iter.empty() // 不合法，(*iter).empty()或iter->empty()。
> iter->empty();  // 判断iter所指字符串是否为空。
> ++*iter;        // 不合法。
> iter++->empty();  // 返回iter->empty()，指针递增。
> ```

## [Exercise 4.21](ex4_21.cpp)

## [Exercise 4.22](ex4_22.cpp)

## Exercise 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
>
> ```cpp
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
> ```

条件运算符的优先级低。

修改：

```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

## Exercise 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

如果是左结合

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
