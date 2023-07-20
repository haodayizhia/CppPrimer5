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

## [Exercise 7.15](ex7_04.h)

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

## [Exercise 7.21](ex7_21_sales_data.h)

## [Exercise 7.22](ex7_04.h)

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

> 初始化的顺序和定义顺序相同，用定义的 `base` 初始化 `rem`。

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

不合法，调用 `Sales_data()` 时有歧义。

## Exercise 7.40

Such as `Book`:

```cpp
class Employee {
   public:
    Employee() = default;
    Employee(std::string _id, std::string _name, std::string _department,
             std::string _position, int _enter_date, double _AnnualSalary)
        : name(_name),
          department(_department),
          position(_position),
          enter_date(_enter_date),
          AnnualSalary(_AnnualSalary) {}

   private:
    std::string id;
    std::string name;
    std::string department;
    std::string position;
    int enter_date;
    double AnnualSalary;
};
```

## Exercise 7.41

[Sales_data Definition](ex7_41_sales_data.h) | [Sales_data Implementation](ex7_41_sales_data.cpp)|[Sales_data Test](ex7_41_sales_data_test.cpp)

## Exercise 7.42

```cpp
class Employee {
   public:
    Employee() = default;
    Employee(std::string _id, std::string _name, std::string _department,
             std::string _position, int _enter_date, double _AnnualSalary)
        : Employee() {
        id = _id, name = _name, department = _department, position = _position,
        enter_date = _enter_date, AnnualSalary = _AnnualSalary;
    }

   private:
    std::string id;
    std::string name;
    std::string department;
    std::string position;
    int enter_date;
    double AnnualSalary;
};
```

## [Exercise 7.43](ex7_43.cpp)

## Exercise 7.44

不合法，只提供数量而略去初始值时，容器中的元素被值初始化，其中当元素是类类型时由类默认初始化， `NoDefault` 没有默认构造函数。

## Exercise 7.45

合法， `C` 有构造函数。

## Exercise 7.46

- a) A class must provide at least one constructor. (**不正确**, "编译器生成的构造函数为合成的默认构造函数")
- b) A default constructor is a constructor with an empty parameter list. (**不正确**, 参数列表包含默认实参的情况下不为空)
- c) If there are no meaningful default values for a class, the class should not provide a default constructor. (**我认为正确**, 默认值无意义时删除或不提供构造函数)
- d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type. (**不正确**, 只有当没有定义任何构造函数时，编译器才会隐式地合成默认的构造函数)

## Exercise 7.47

取决于是否需要利用该构造函数的隐式转换。

Benefits:

- 避免未预料到的隐式转换
- 使该构造函数只能以直接初始化的方式使用

Drawbacks:

- 不够方便

## Exercise 7.48

`item1` 和 `item2` 都是接收一个 `string` 参数构造出来的 `Sales_data` 类。

## Exercise 7.49

```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // 错误，类型不匹配且无法转换
(c) Sales_data &combine(const Sales_data&) const; // 错误，const函数不能改变类对象
```

Some detailed explanation about problem (b) :

## [Exercise 7.50](ex7_04.h)

目前没有。

## Exercise 7.51

`string` 这样用可以提供便利， `vector`这样用引发歧义。

## Exercise 7.52

列表初始化聚合类，聚合类不应该有类内初始值：

修改:

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## [## Exercise 7.53](ex7_53.h)

## Exercise 7.54

不能， `constexpr` 函数能拥有的唯一可执行语句就是返回语句，具备隐式 `const` 属性。

## Exercise 7.55

不是，数据成员都是字面值类型的聚合类才是字面值常量类。如：

```cpp
struct Data {
    int ival;
    char c;
};
```

## Exercise 7.56

> What is a static class member?

类的静态成员属于类，但与类的对象无关。

优点：共享信息，并且静态成员值改变，所有对象都能使用新值。

> 区别

- 静态成员可以是不完全类型
- 静态成员可作为默认实参

## [Exercise 7.57](ex7_57.h)

## Exercise 7.58

```cpp
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            只能在类内初始化字面值常量类型的静态成员.
```+

Fixed:

```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
