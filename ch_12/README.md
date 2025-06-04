# Chapter 12. Dynamic Memory

## Exercise 12.1

>How many elements do b1 and b2 have at the end of this code?

```cpp
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```

两个对象共享底层数据, 所以都是4个元素, 但是b2被销毁了.

## Exercise 12.2

[StrBlob](ex12_02.h) | [TEST](ex12_02_TEST.cpp)

## Exercise 12.3

>Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?

不需要, 虽然容器内的元素是指针, 可以添加const版本, 但是通常const函数不应涉及修改容器元素内容.

## Exercise 12.4

>In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?

因为 `i` 是无符号整型, 赋予其小于0的值也会被转化为正整数.

## Exercise 12.5

>We did not make the constructor that takes an initializer_list explicit (7.5.4, p. 296). Discuss the pros and cons of this design choice.

优点: 可以自动转换类型, 更方便.

缺点: 可能发生期望之外的转换, 容易出错.

## [Exercise 12.6](ex12_06.cpp)

## [Exercise 12.7](ex12_07.cpp)

## Exercise 12.8

>Explain what if anything is wrong with the following function.

```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```
指针p会被转换为bool类型, 动态内存将没有机会被释放, 因此会导致内存泄漏.

## Exercise 12.9

>Explain what happens in the following code:

```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

`r=q` 会导致内存泄露, 而 `r2=q2` 由于是动态内存安全.

## Exercise 12.10

正确, 但是没有必要用临时智能指针, 可以直接`process(p)`.

## Exercise 12.11

p指向的内存空间会在process函数结束时被释放, 从而p变成空虚指针, 使用p时发生未定义的行为且p被销毁时内存会被第二次delete.

## Exercise 12.12

(a) 引用计数加一.

(b) 不合法, 接受指针参数的智能指针构造函数是explicit的, 不能进行内置指针到智能指针的隐式转换.

(c) 同上, 不合法.

(d) 合法, 但是内存会被释放, p变为空虚指针.

## Exercise 12.13

delete get返回的指针, sp变成空悬指针, 使用时发生未定义的行为且被二次销毁.

## [Exercise 12.14](ex12_14.cpp)

## [Exercise 12.15](ex12_15.cpp)

## [Exercise 12.16](ex12_16.cpp)

## Exercise 12.17

(a) 错误，参数应该为动态分配内存的指针。

(b)错误，同上。

(c)合法，但是要注意内存会被unique_ptr释放。

(d)错误，同(b)。

(e)合法。

(f)错误，p2没有get成员。

## Exercise 12.18

shared_ptr 指向的内存在引用计数为0时才会被释放，单个该指针不支持释放。

## Exercise 12.19 [Header](ex12_19.h)|[Implementation](ex12_19.cpp)

## [Exercise 12.20](ex12_20.cpp)

## Exercise 12.21

>We could have written StrBlobPtr’s deref member as follows:

```cpp
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```

Which version do you think is better and why?

之前的版本好，更直观。

## [Exercise 12.22](ex12_22.h)

## [Exercise 12.23](ex12_23.cpp)

## [Exercise 12.24](ex12_24.cpp)

## Exercise 12.25

>Given the following new expression, how would you delete pa?

```cpp
int *pa = new int[10];
```

```cpp
delete [] pa;
```

## [Exercise 12.26](ex12_26.cpp)

## Exercise 12.27 [Header](ex12_27.h)|[Test](ex12_27.cpp)

## [Exercise 12.28](ex12_28.cpp)

## Exercise 12.29

>We could have written the loop to manage the interaction with the user as a do while (5.4.4, p. 189) loop. Rewrite the loop to use a do while. Explain which version you prefer and why.

```cpp
do {
    std::cout << "enter word to look for, or q to quit: " << std::endl;
    std::string queryWord;
    if (!(std::cin >> queryWord) || queryWord == "q") break;
    print(std::cout, tq.query(queryWord)) << std::endl;
} while (true)
```

效果一样，`do while` 更符合直觉。

## Exercise 12.30 [Header](ex12_30.h)|[Test](ex12_30_TEST.cpp)

## Exercise 12.31

>What difference(s) would it make if we used a vector instead of a set to hold the line numbers? Which approach is better? Why?

`set` 更好，可以保证不重复和自动排序。

## Exercise 12.32 [Header](ex12_32.h)

## Exercise 12.33 [Header](ex12_33.h)

基于 [ex12_30.h](ex12_30.h) 添加。
