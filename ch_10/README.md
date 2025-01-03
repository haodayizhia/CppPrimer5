# Chapter 10. Generic Algorithms

## [Exercise 10.1 and 10.2](ex10_01_02.cpp)

## [Exercise 10.3 and 10.4](ex10_03_04.cpp)

## [Exercise 10.5](ex10_05.cpp)

## [Exercise 10.6](ex10_06.cpp)

## Exercise 10.7

- (a) 错误, 传递给`copy`的目的序列至少要包含与输入序列一样多的元素, 这里应该用`back_inserter`.

* (b) 错误, `reserve`改变的容器的内存空间, 而不是元素个数, 可以用`resize`.


## Exercise 10.8

> We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?

因为算法是运行于迭代器之上的, 与容器类型无关. 而`back_inserter`是对容器的操作, 会调用容器的`push_back`将元素添加到容器中.

## [Exercise 10.9](ex10_09.cpp)

## Exercise 10.10

> Why do you think the algorithms don’t change the size of containers?

算法运行于迭代器之上, 是对容器的元素进行操作, 要改变容器的大小应当使用容器的操作.

## [Exercise 10.11](ex10_11.cpp)

## [Exercise 10.12](ex10_12.cpp)

## [Exercise 10.13](ex10_13.cpp)

## Exercise 10.14

> Write a lambda that takes two ints and returns their sum.

```cpp
auto add = [](int lhs, int rhs){return lhs + rhs;};
```

## Exercise 10.15

> Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.

```cpp
int i = 42;
auto add = [i](int num){return i + num;};
```

## [Exercise 10.16](ex10_16.cpp)

## [Exercise 10.17](ex10_17.cpp)

## [Exercise 10.18](ex10_18.cpp)

## [Exercise 10.19](ex10_19.cpp)

## [Exercise 10.20](ex10_20.cpp)

## [Exercise 10.21](ex10_21.cpp)

## [Exercise 10.22](ex10_22.cpp)

## Exercise 10.23

> How many arguments does bind take?

Assuming the function to be bound have `n` parameters, bind take `n + 1` parameters. The additional one is for the function to be bind itself.

## [Exercise 10.24](ex10_24.cpp)

## [Exercise 10.25](ex10_25.cpp)

## Exercise 10.26

> Explain the differences among the three kinds of insert iterators.

- `back_inserter` uses `push_back`.
- `front_inserter` uses `push_front`.
- `insert` uses `insert` >This function takes a second argument, which must be an iterator into the given container. Elements are inserted ahead of the element denoted by the given iterator.

## [Exercise 10.27](ex10_27.cpp)

## [Exercise 10.28](ex10_28.cpp)

## [Exercise 10.29](ex10_29.cpp)

## [Exercise 10.30](ex10_30.cpp)

## [Exercise 10.31](ex10_31.cpp)

## [Exercise 10.32](ex10_32.cpp)

## [Exercise 10.33](ex10_33.cpp)

## [Exercise 10.34 ~ 10.37](ex10_34_35_36_37.cpp)

## Exercise 10.38

> List the five iterator categories and the operations that each supports.

- Input iterators : `==`, `!=`, `++`, `*`, `->`
- Output iterators : `++`, `*`
- Forward iterators : `==`, `!=`, `++`, `*`, `->`
- Bidirectional iterators : `==`, `!=`, `++`, `--`, `*`, `->`
- Random-access iterators : `==`, `!=`, `<`, `<=`, `>`, `>=`, `++`, `--`, `+`, `+=`, `-`, `-=`, `-`(two iterators), `*`, `->`, `iter[n]` == `* (iter + n)`

## Exercise 10.39

> What kind of iterator does a list have? What about a vector?

`list` have the **Bidirectional iterators**. `vector` have the **Random-access iterators**.

## Exercise 10.40

> What kinds of iterators do you think copy requires? What about reverse or unique?

- `copy` : first and second are Input iterators, last is Output iterators.
- `reverse` : Bidirectional iterators.
- `unique` : Forward iterators.

## Exercise 10.41

> Based only on the algorithm and argument names, describe the operation that the each of the following library algorithms performs:

```cpp
replace(beg, end, old_val, new_val); // 将输入范围中的值old_val替换为新值.
replace_if(beg, end, pred, new_val); // 将输入范围中使得谓词返回为非0值的元素替换..
replace_copy(beg, end, dest, old_val, new_val); // 将输入范围中的旧值替换为新值并输出到目标迭代器.
replace_copy_if(beg, end, dest, pred, new_val); // 将输入范围中使得谓词返回为非0值的元素替换为新值并输出到目标迭代器.
```

## [Exercise 10.42](ex10_42.cpp)
