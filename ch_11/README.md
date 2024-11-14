# Chapter 11. Associative Containers

## Exercise 11.1

>Describe the differences between a map and a vector.

`map` 保存的元素为值-对`pair`, 按关键字的顺序保存和访问元素, 而且访问值的下标是关键字, 支持高效的关键字查找和访问.

`vector` 存储的元素下标为整数, 按下标顺序保存和访问元素.

## Exercise 11.2

>Give an example of when each of list, vector, deque, map, and set might be most useful.

- `list` : 需要频繁插入或删除元素的序列, 如游戏任务表.
- `vector` : 需要快速随机访问的序列, 如每天的天气.
- `deque` : 提供快速访问并首位删除或添加的序列, 如排队列表.
- `map` : 提供快速查找和访问, 如字典和电话本.
- `set` : 提供快速查找, 如黑名单.

## [Exercise 11.3 and 11.4](ex11_3_4.cpp)

## Exercise 11.5

>Explain the difference between a map and a set. When might you use one or the other?

- `set` : 元素类型是关键字.
- `map` : 元素类型为关键字-值对.

当只需要保存关键字时用 `set` , 当需要关键字-值的映射关系时用 `map` .

## Exercise 11.6

>Explain the difference between a set and a list. When might you use one or the other?

`set` 不允许重复关键字且按关键字顺序排序, 支持高效的查找和访问. 而 `list` 允许重复且支持双向顺序访问, 频繁插入和删除元素时更高效.

## [Exercise 11.7](ex11_7.cpp)

## [Exercise 11.8](ex11_8.cpp)

## [Exercise 11.9 and 11.10](ex11_9_10.cpp)

## [Exercise 11.11](ex11_11.cpp)

## [Exercise 11.12 and 11.13](ex11_12_13.cpp)

## [Exercise 11.14](ex11_14.cpp)

## Exercise 11.15

>What are the `mapped_type`, `key_type`, and `value_type` of a `map` from int to `vector<int>`?

- `mapped_type` : `vector<int>`
- `key_type` : `int`
- `value_type` : `std::pair<const int, vector<int>>`

## Exercise 11.16

>Using a map iterator write an expression that assigns a value to an element.

```cpp
std::map<int, std::string> map;
map[25] = "Alan";
std::map<int, std::string>::iterator it = map.begin();
it->second = "Wang";
```

## Exercise 11.17

>Assuming c is a multiset of strings and v is a vector
of strings, explain the following calls. Indicate whether each call is legal:

```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```

## Exercise 11.18
`std::map<std::string, size_t>::iterator`

## Exercise 11.19

>Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425).
Write the variable’s type without using auto or decltype.

```cpp
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```

## [Exercise 11.20](ex11_20.cpp)

## Exercise 11.21

>Assuming word_count is a map from string to size_t and word is a string, explain the following loop:

```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```

```cpp
++ (word_count.insert({word, 0}).first->second)
```

## Exercise 11.22

>Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.

```cpp
std::map<std::string, std::vector<int>> m;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = m.insert({"code", {1, 2}});
```

## [Exercise 11.23](ex11_23.cpp)

## Exercise 11.24

>What does the following program do?

```cpp
     map<int, int> m;
     m[0] = 1;
     add a key-value pair {0,1} into the map
```

创建一个 `map` 并插入一个关键字为0的元素, 关联值进行值初始化, 然后将1赋予它.

## Exercise 11.25

>Contrast the following program with the one in the previous exercise

```cpp
     vector<int> v;
     v[0] = 1;
```

由于 `v` 为空, 访问一个不存在的元素会提示错误.

## [Exercise 11.26](ex11_26.cpp)

## Exercise 11.27

>What kinds of problems would you use count to solve? When might you use find instead?

对只需要搜索 `set` 和 `map` 使用 `find`, 对需要搜索并计数的 `multi_set` 和 `multi_map` 使用 `count`.

## [Exercise 11.28](ex11_28.cpp)

## Exercise 11.29

>What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?

`upper_bound` 返回第一个大于关键字的迭代器, `lower_bound` 返回第一个不小于关键字的迭代器, 此时它们是指向同一个关键字安全插入点的迭代器, `equal_range` 返回一个 `{lower_bound, upper_bound}` 的 `pair`.

## [Exercise 11.30]

>Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.

`pos.first` 返回从 `upper_bound` 开始循环递增的迭代器, `pos.first->second` 返回迭代器所指容器元素中的 `mapped_type`.

## [Exercise 11.31](ex11_31.cpp)

## [Exercise 11.32](ex11_32.cpp)

## [Exercise 11.33](ex11_33.cpp)

## Exercise 11.34

>What would happen if we used the subscript operator instead of find in the transform function?

In gcc 4.8.3, will report error:

```cpp
error: passing ‘const std::map<std::basic_string<char>, std::basic_string<char> >’ as ‘this’ argument of ‘std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type& std::map<_Key, _Tp, _Compare, _Alloc>::operator[](const key_type&) [with _Key = std::basic_string<char>; _Tp = std::basic_string<char>; _Compare = std::less<std::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::basic_string<char>, std::basic_string<char> > >; std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type = std::basic_string<char>; std::map<_Key, _Tp, _Compare, _Alloc>::key_type = std::basic_string<char>]’ discards qualifiers [-fpermissive]
     auto key = m[s];
                   ^
```

Because std::map's operator is not declared as **const**,but m is declared as a  reference to  std::map with **const**.If insert new pair,it will cause error.

## Exercise 11.35

>In buildMap, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({key, value.substr(1)})`?

- use subscript operator: if a word does appear multiple times, our loops will put the **last** corresponding phrase into trans_map
- use `insert`: if a word does appear multiple times, our loops will put the **first** corresponding phrase into trans_map

## Exercise 11.36

>Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible.
What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

we added a file that name "word_transformation_bad.txt" to folder `data`. the file only has a key, one space.

the program of 11.33 don't influenced by that.

## Exercise 11.37

>What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

- the advantages of an unordered container:
    - useful when we have a key type for which there is no obvious ordering relationship among the elements
    - useful for applications in which the cost of maintaining the elements in order is prohibitive
- the advantages of the ordered version:
    - Iterators for the ordered containers access elements in order by key
    - we can directly define an ordered container that uses a our own class types for its key type.

## [Exercise 11.38](ex11_38.cpp)
