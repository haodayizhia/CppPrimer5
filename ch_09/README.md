# Chapter 9. Sequential Containers

## Exercise 9.1

>Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?Explain the rationale for your choice.If there is no reason to prefer one or another container, explain why not.
>
>- (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
>- (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
>- (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

* (a) `std::set` 最合适，其次 `list` 优于 `vector` 或 `deque` ，因为需要大量中间插入元素。
* (b) `deque` ，需要在头尾插入或删除元素。
* (c) `vector` ，不需要插入元素。

## Exercise 9.2

>Define a list that holds elements that are deques that hold ints.

```cpp
std::list<std::deque<int>> ldi;
```

## Exercise 9.3

>What are the constraints on the iterators that form iterator ranges?

two iterators, `begin` and `end`:

* 两个迭代器指向同一个容器中的元素或者是尾元素之后的位置。
* 可以通过反复递增 `begin` 来到达 `end`。

## Exercise 9.4

>Write a function that takes a pair of iterators to a `vector<int>` and an int value. Look for that value in the range and return a bool indicating whether it was found.

```cpp
bool find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
    for (auto iter = beg; iter != end; ++iter)
        if (*iter == value) return true;
    return false;
}
```

## Exercise 9.5

>Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```cpp
vector<int>::iterator find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
    for (auto iter = beg; iter != end; ++iter)
        if (*iter == value) return iter;
    return end;
}
```

## Exercise 9.6

>What is wrong with the following program? How might you correct it?

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /*ERROR: operator< can't be applied to iterator for list*/
```

Fixed:

```cpp
while(iter1 != iter2)
```

### note

`list` 支持 `<` 关系运算符，但迭代器不支持。

## Exercise 9.7

>What type should be used as the index into a vector of ints?

    vector<int>::size_type

## Exercise 9.8

>What type should be used to read elements in a list of strings? To write them?

    list<string>::iterator || list<string>::const_iterator // read
    list<string>::iterator // write

## Exercise 9.9

>What is the difference between the `begin` and `cbegin` functions?

`cbegin` 是 const 成员，返回容器的 **const_iterator**。

`begin` 是重载函数，一个是 const 成员，另一个是非 const 成员。

## Exercise 9.10

>What are the types of the following four objects?

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

-----

[@shidenggui](https://github.com/shidenggui):

题中给出的代码会报错:

> ```bash
> **error**: inconsistent deduction for ‘auto’: ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’ and then ‘__gnu_cxx::__normal_iterator<const int*, std::vector<int> >’ auto it1 = v1.begin(), it2 = v2.begin();
> ```

the correct codes should be:

```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

-----

`it1` 为 `vector<int>::iterator`

`it2`,`it3` 和 `it4` 为 `vector<int>::const_iterator`

## Exercise 9.11

>Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

```cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 0
vector<int> vec(10,1);  // 1
vector<int> vec{1,2,3,4,5}; // 1,2,3,4,5
vector<int> vec(other_vec); // same as other_vec
vector<int> vec(other_vec.begin(), other_vec.end()); // same as other_vec
```

## Exercise 9.12

>Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

* 接受一个容器创建其拷贝的构造函数要求容器类型及元素类型匹配，并会拷贝容器内所有元素:

```cpp
list<int> numbers = {1, 2, 3, 4, 5};
list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers);      // error: no matching function for call...
list<double> numbers4(numbers);     // error: no matching function for call...
```

* 接受两个迭代器创建其拷贝的构造函数不要求容器类型及元素类型相同，只要能将要拷贝的元素转换为要初始化的容器的元素，并只拷贝迭代器范围内的元素：
```cpp
list<int> numbers = {1, 2, 3, 4, 5};
list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is {1, 2, 3, 4}
list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is {2, 3, 4}
forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is {1, 2, 3, 4, 5}
```

## [Exercise 9.13](ex9_13.cpp)

## [Exercise 9.14](ex9_14.cpp)

## [Exercise 9.15](ex9_15.cpp)

## [Exercise 9.16](ex9_16.cpp)

报错：error: no match for 'operator<' (operand types are 'std::__cxx11::list<int>' and 'std::vector<int>')。

## Exercise 9.17

>Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

```cpp
if (c1 < c2)
```

* 都不是无序关联容器
* 容器类型相同，且保存相同类型的元素
* 元素支持 `<` 运算符

## [Exercise 9.18](ex9_18.cpp)

## [Exercise 9.19](ex9_19.cpp)

## [Exercise 9.20](ex9_20.cpp)

## Exercise 9.21

>Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

结果相同。
>The first call to `insert` takes the `string` we just read and puts it in front of the element denoted by `iter`. The value returned by `insert` is an iterator referring to this new element. We assign that iterator to `iter` and repeat the `while`, reading another word. As long as there are words to insert, each trip through the `while` inserts a new element ahead of `iter` and reassigns to `iter` the location of the newly inserted element. That element is the (new) first element. Thus, each iteration inserts an element ahead of the first element in the `vector`.

## Exercise 9.22

>Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?

```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

**Problems:**

1. 无限循环。
2. 迭代器在插入后失效。(see [Mooophy/Cpp-Primer#133](https://github.com/Mooophy/Cpp-Primer/issues/133))

**FIXED**:

check [this](ex9_22.cpp).

## Exercise 9.23

>In the first program in this section on page 346, what would
the values of val, val2, val3, and val4 be if c.size() is 1?

都等于首元素的值。

## [Exercise 9.24](ex9_24.cpp)

## Exercise 9.25

>In the program on page 349 that erased a range of
elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

如果elem1和elem2相等，不做任何事。

如果elem2是尾后迭代器，将从elem1开始的所有元素删除。

如果elem1和elem2都是尾后迭代器，不做任何事。

## [Exercise 9.26](ex9_26.cpp)

## [Exercise 9.27](ex9_27.cpp)

## Exercise 9.28

>Write a function that takes a `forward_list<string>` and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.

[x9_28.cpp](ex9_28_TEST.cpp)

## Exercise 9.29

>Given that vec holds 25 elements, what does
vec.resize(100) do? What if we next wrote vec.resize(10)?

```cpp
vec.resize(100);    // adds 75 items to the back of vec. These added items are value initialized.
vec.resize(10);     // erases 90 elements from the back of vec
```

## Exercise 9.30

>What, if any, restrictions does using the version of resize
that takes a single argument place on the element type?

If the container holds elements of a class type and resize adds elements, we must supply an **initializer** or the element type must have a **default constructor**.

## Exercise 9.31 [use list](ex9_31_1.cpp) | [use forward_list](ex9_31_2.cpp)

## [Exercise 9.32](ex9_32.cpp)

## [Exercise 9.33](ex9_33.cpp)

## [Exercise 9.34](ex9_34.cpp)

## Exercise 9.35

>Explain the difference between a vector’s capacity and its size.

The **size** of a container is the number of **elements** it already holds;

The **capacity** is how many elements it can hold before more **space** must be allocated.

## Exercise 9.36

>Can a container have a capacity less than its size?

cannot.

## Exercise 9.37

>Why don’t list or array have a capacity member?

`list` elements does not store contiguously. `array` has the fixed size, thus cannot added elements to it.

## [Exercise 9.38](ex9_38.cpp)

## Exercise 9.39

>Explain what the following program fragment does:

```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
```

The `while` loop will read words from `cin` and store them in out vector. Even if we initially reserved 1024 elements, if there are more words read from `cin`, our vector's capacity will be automatically increased (most implementations will double the previous capacity) to accommodate them.

And now comes the catch. `resize()` is different from `reserve()`. In this case `resize()` will add another `svec.size()/2` value initialized elements to `svec`. If this exceeds `svec.capacity()` it will also automatically increase it to accommodate the new elements.

## Exercise 9.40

>If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?

read | size | capacity
------ | ------ | ------
256 | 384 | 1024
512 | 768 | 1024
1000 | 1500 | 2000(clang is 2048)
1048 | 1572 | 2048

## [Exercise 9.41](ex9_41.cpp)

## Exercise 9.42

>Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

Use member `reserve(120)` to allocate enough space for this string. (@Mooophy)

## [Exercise 9.43](ex9_43.cpp)

## [Exercise 9.44](ex9_44.cpp)

## [Exercise 9.45](ex9_45.cpp)

## [Exercise 9.46](ex9_46.cpp)

## Exercise 9.47 [find_first_of](ex9_47_1.cpp) | [find_first_not_of](ex9_47_2.cpp)

## Exercise 9.48

>Given the definitions of name and numbers on page 365,
what does numbers.find(name) return?

string::npos

## [Exercise 9.49](ex9_49.cpp)

## [Exercise 9.50](ex9_50.cpp)

## [Exercise 9.51](ex9_51.cpp)

## [Exercise 9.52](ex9_52.cpp)
