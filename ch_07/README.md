# Chapter 7. Classes

## [Exercise 7.1](ex7_01.cpp)

## [Exercise 7.2](ex7_02_sales_data.h)

## [Exercise 7.3](ex7_03.cpp)

## [Exercise 7.4](ex7_04.h)

## [Exercise 7.5](ex7_05.h)

应该是 `const` ，返回操作不改变对象。

## [Exercise 7.6](ex7_06_sales_data.h)

## [Exercise 7.7](ex7_07.cpp)

## Exercise 7.8

输入会改变变量，而输出不会改变。

## [Exercise 7.9](ex7_09.h)

## Exercise 7.10

```cpp
if(read(read(cin, data1), data2))
```

判断是否成功读取两个 `Sales_data` 。

## Exercise 7.11

[Sales_data Definition](ex7_11_sales_data.h) | [Sales_data Implementation](ex7_11_sales_data.cpp)

## [Exercise 7.12](ex7_12_sales_data.h)

需要提前声明。

## [Exercise 7.13](ex7_13.cpp)

注意判断条件的 `cin` 。

## Exercise 7.14

```cpp
Sales_data() : units_sold(0) , revenue(0){}
```

## [Exercise 7.15](ex7_15.h)

## Exercise 7.16

没有限制，每个访问说明符的有效范围直到出现下一个访问说明符或者到达类的结尾为止。

`public` 成员定义类的接口，后面跟着构造函数和部分成员函数。

`private` 封装了类的实现细节，数据成员和作为实现部分的函数跟在 `private` 后面。

## Exercise 7.17

唯一的区别是默认访问权限， `struct` 第一个访问说明符之前的成员是 `public` 的， `class` 第一个访问说明符之前的成员是 `private` 的。

## Exercise 7.18

封装是实现和接口的分离，隐藏了类型实现的细节。（C++中，将实现放在类的 `class` 中来封装）

---

用处：

- 确保用户代码不会无意间破坏封装对象的状态。
- 被封装的类的具体实现细节可以随时改变，而而无须调整用户级别的代码。

## Exercise 7.19

- `public`: 构造函数。
- `private`: 数据成员。

提供接口，保护数据成员。

## Exercise 7.20

允许其他类或函数访问类的非公有成员时。

**利**:

- 可以访问类作用域中的名称而无需加类名前缀。
- 可以方便地访问所有的非公有成员。

**弊**:

- 降低了封装性。

## [Exercise 7.21](ex7_04.h)

## [Exercise 7.22](ex7_22.h)

## [Exercise 7.23](ex7_23.h)

## [Exercise 7.24](ex7_23.h)

## Exercise 7.25

可以，动态内存使用的 `vector` 和 `string`，类合成的版本可以正常工作。

## [Exercise 7.26](ex7_06_sales_data.h)

## [Exercise 7.27](ex7_23.h)

## Exercise 7.28

前者临时拷贝有 #，后者没有 #。

## Exercise 7.29

```sh
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

## Exercise 7.30

**优点**

- 可以使用和成员名相同的函数参数名。

```cpp
void setAddr(const std::string &addr) {this->addr = addr;}
```

**缺点**

- 阅读更长
- 冗余

```cpp
std::string getAddr() const { return this->addr; } // unnecessary
```

## [Exercise 7.31](ex7_31.h)

## [Exercise 7.32](ex7_32.h)

## Exercise 7.33

[clang]error: unknown type name 'pos'

fixed:

```cpp
Screen::pos Screen::size() const
{
    return height*width;
}
```

## Exercise 7.34

There is an error in

```cpp
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```

## Exercise 7.35

```cpp
typedef string Type;
Type initVal(); // use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // use `double`
    Type initVal(); // use `double`
private:
    int val;
};

Type Exercise::setVal(Type parm) {  // first is `string`, second is `double`
    val = parm + initVal();     // Exercise::initVal()
    return val;
}
```

### fixed

changed

```cpp
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

to

```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

and `Exercise::initVal()` should be defined.

## Exercise 7.36

> In this case, the constructor initializer makes it appear as if `base` is initialized with `i` and then `base` is used to initialize `rem`. However, `base` is initialized first. The effect of this initializer is to initialize `rem` with the undefined value of `base`!

### fixd

```cpp
struct X {
  X (int i, int j): base(i), rem(base % j) { }
  int base, rem;
};
```

## Exercise 7.37

```cpp
Sales_data first_item(cin);   // use Sales_data(std::istream &is) ; its value are up to your input.

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## Exercise 7.38

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## Exercise 7.39

illegal. cause the call of overloaded 'Sales_data()' is **ambiguous**.

## Exercise 7.40

Such as `Book`:

```cpp
class Book {
public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate) : no_(no), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> no_ >> name_ >> author_ >> pubdate_; }

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## Exercise 7.41

[Sales_data Definition](ex7_41_sales_data.h) | [Sales_data Implementation](ex7_41_sales_data.cpp)|[Sales_data Test](ex7_41_sales_data_test.cpp)

## Exercise 7.42

```cpp
class Book {
public:
  Book(unsigned no, std::string name, std::string author, std::string pubdate):no_(no), name_(name), author_(author), pubdate_(pubdate) { }
  Book() : Book(0, "", "", "") { }
  Book(std::istream &in) : Book() { in >> no_ >> name_ >> author_ >> pubdate_; }

private:
  unsigned no_;
  std::string name_;
  std::string author_;
  std::string pubdate_;
};
```

## [## Exercise 7.43](ex7_43.cpp)

## Exercise 7.44

illegal, cause there are ten elements, each would be value initialized. But no default constructor for `NoDefault` type.

## Exercise 7.45

No problem. cause `C` have the default constructor.

## Exercise 7.46

- a) A class must provide at least one constructor. (**untrue**, "The compiler-generated constructor is known as the synthesized default constructor.")
- b) A default constructor is a constructor with an empty parameter list. (**untrue**, A default constructor is a constructor that is used if no initializer is supplied.What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor)
- c) If there are no meaningful default values for a class, the class should not provide a default constructor. (**untrue**, the class should provide.)
- d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type. (**untrue**, only if our class does not explicitly define **any constructors**, the compiler will implicitly define the default constructor for us.)

## Exercise 7.47

Whether the conversion of a `string` to `Sales_data` is desired **depends on how we think our users will use the conversion**. In this case, it might be okay. The `string` in null_book probably represents a nonexistent ISBN.

Benefits:

- prevent the use of a constructor in a context that requires an implicit conversion
- we can define a constructor which is used only with the direct form of initialization

Drawbacks:

- meaningful only on constructors that can be called with a single argument

## Exercise 7.48

Both are noting happened.

## Exercise 7.49

```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // [Error] no matching function for call to 'Sales_data::combine(std::string&)' (`std::string&` can not convert to `Sales_data` type.)
(c) Sales_data &combine(const Sales_data&) const; // The trailing const mark can't be put here, as it forbids any mutation on data members. This conflicts with combines semantics.
```

Some detailed explanation about problem (b) :

It's wrong.

Because `combine`’s parameter is a non-const reference , we can't pass a temporary to that parameter. If `combine`’s parameter is a reference to `const` , we can pass a temporary to that parameter. Like this :`Sales_data &combine(const Sales_data&);` Here we call the `Sales_data` `combine` member function with a string argument. This call is perfectly legal; the compiler automatically creates a `Sales_data` object from the given string. That newly generated (temporary) `Sales_data` is passed to `combine`.(check on page 295(English Edition))

## [Exercise 7.50](ex7_50.h)

## Exercise 7.51

Such as a function like that:

```cpp
int getSize(const std::vector<int>&);
```

if vector has not defined its single-argument constructor as explicit. we can use the function like:

```cpp
getSize(34);
```

What is this mean? It's very confused.

But the `std::string` is different. In ordinary, we use `std::string` to replace `const char *`(the C language). so when we call a function like that:

```cpp
void setYourName(std::string); // declaration.
setYourName("pezy"); // just fine.
```

it is very natural.

## Exercise 7.52

In my opinion ,the aim of the problem is Aggregate Class. Test-makers think that `Sales_data` is Aggregate Class,so `Sales_data` should have no in-class initializers if we want to initialize the data members of an aggregate class by providing a braced list of member initializers:

FIXED:

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## [## Exercise 7.53](ex7_53.h)

## Exercise 7.54

shouldn't, cause a `constexpr` function must contain exactly one **return** statement.

## Exercise 7.55

no.

`std::string` is not a literal type, and it can be verified by following codes:

```cpp
#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
```

## Exercise 7.56

> What is a static class member?

A class member that is **associated with the class**, rather than with individual objects of the class type.

> What are the advantages of static members?

each object can no need to store a common data. And if the data is changed, each object can use the new value.

> How do they differ from ordinary members?

- a static data member can have **incomplete type**.
- we can use a static member **as a default argument**.

## [Exercise 7.57](ex7_57.h)

## Exercise 7.58

```cpp
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            we may not specify an in-class initializer inside parentheses.
```

Fixed:

```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
