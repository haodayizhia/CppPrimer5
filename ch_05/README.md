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
