# Chapter 2. Variables and Basic Types

## Exercise 2.1

> What are the differences between `int`, `long`, `long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?

所占比特数不同，能表示的数据范围也不一样。`int` 最小尺寸16位，`long` 最小32位，`long long` 最小64位比特。

带符号类型可以表示正数、负数或0，无符号类型仅能表示大于等于0的值。

浮点型可表示为单精度、双精度和扩展精度值。`float` 一个字（32比特，7个有效位），`double` 两个字（64比特，16个有效位）,`long double` 3个字或4个字。

## Exercise 2.2

> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

浮点型，本金和付款位数较多，选用double，利率可以使用float。
