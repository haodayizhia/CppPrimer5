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
## Exercise 4.25

> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which '`q`' has the bit pattern `01110001`?

首先， `char` 类型提升为 `int` ， `00000000 00000000 00000000 01110001` ，然后取反左移6位，为 `11111111 11111111 11100011 10000000`，等于-7296。

## Exercise 4.26

> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

30个学生，用 `unsigned int` 只有16位，结果未定义。

## Exercise 4.27

> What is the result of each of these expressions?
>
> ```cpp
> unsigned long ul1 = 3, ul2 = 7;
> ul1 & ul2 // == 3
> ul1 | ul2 // == 7
> ul1 && ul2 // == true
> ul1 || ul2 // == ture
> ```

## [Exercise 4.28](ex4_28.cpp)

## Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
>
> ```cpp
> int x[10];   int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

第一个结果为10，第二个在64位机器上为2，在32位机器上为1。

## Exercise 4.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
>
> ```cpp
> sizeof x + y      // (sizeof x)+y . "sizeof" has higher precedence than binary`\+`.
> sizeof p->mem[i]  // sizeof(p->mem[i])
> sizeof a < b      // sizeof(a) < b
> sizeof f()        // if`f()`returns`void`, this statement is undefined, otherwise it returns the size of return type.
> ```

## Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

没有区别，建议用前置，可能效率更高。

## Exercise 4.32

> Explain the following loop.
>
> ```cpp
> constexpr int size = 5;
> int ia[size] = {1,2,3,4,5};
> for (int *ptr = ia, ix = 0;
>     ix != size && ptr != ia+size;
>     ++ix, ++ptr) { /* ... */ }
> ```

`ptr` 指针和 `ix` 下标随整型数组遍历递增。

## Exercise 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:
>
> ```cpp
> someValue ? ++x, ++y : --x, --y
> ```

如果结果为真， `++x, ++y` ，返回 `++y` 的值；如果结果为假，反之。

## Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
>
> (a) if (fval)
> (b) dval = fval + ival;
> (c) dval + ival * cval;

Remember that you may need to consider the associativity of the operators.

```cpp
if (fval) // float转换为bool
dval = fval + ival; // int转换为float，然后相加的结构转换为double
dval + ival * cval; // char转换为int，然后乘积转换为double
```
## Exercise 4.35

> Given the following definitions,
>
> ```cpp
> char cval; int ival; unsigned int ui; float fval; double dval;
> ```
>
> identify the implicit type conversions, if any, taking place:
>
> ```cpp
> cval = 'a' + 3; // 字符字面值常量转换为int，然后结果转换为char
> fval = ui - ival * 1.0; // int转换为double，unsigned int同样转换为double，结果转换为float（损失精度）
> dval = ui * fval; // unsigned int转换为float，然后float转换为double
> cval = ival + fval + dval;  // int转换为float，然后float转换为double，最后转换为char
> ```

## Exercise 4.36

> Assuming i is an int and d is a double write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
>
> ```cpp
> int i; double d; const string *ps; char *pc; void *pv;
> pv = (void*)ps; // pv = const_cast<string*>(ps); or pv = static_cast<void*>(const_cast<string*>(ps));
> i = int(*pc);   // i = static_cast<int>(*pc);
> pv = &d;        // pv = static_cast<void*>(&d);
> pc = (char*)pv; // pc = reinterpret_cast<char*>(pv);
> ```
  
  ## Exercise 4.38

> Explain the following expression:
>
> ```cpp
> double slope = static_cast<double>(j/i);
> ```

把整型的 `j/i` 转换为双精度类型，赋值给slope。
