首先介绍一下 String 的简单定义。

以下是我自己认为的 ~~不知道对不对~~。

因为 C++ 本身就是一门面向对象的语言设计规范，所以我是这么理解的。在 C++ 要满足了一种**方式**去代替一个字符序列，这种所谓的**方式**就是`std::string`类。而针对一个具体的字符串其实就是`std::string`类的一个具体实例，也就是我们常说的对象`object`。

> 字符串被视为是一个字符数组，在c++中包含 `std::string`类，这个类被用于代替字符串。

## 字符串 VS 字符数组
| String    | Char Array    |
| --- | --- |
|一个字符串是string类的一个对象，被作为一个字符序列的替代品。     | 字符数组只是可以由 null 字符终止的字符数组。    |
|字符串的内存是动态分配的，可以在运行时按需分配，因此不会有内存浪费。     |字符数组的大小是静态分配的，内存分配过小，如果在运行时需要更大的内存是无法分配的；内存分配过大且未使用，也是一种浪费。     |
|字符串作为一个对象，不会发生*数组衰减*。     |在字符数组中，会存在数组衰减。     |
|在大多数情境下，字符串比字符数组要慢。     |字符数组的实现比字符串更快     |
> 数组衰减（Array Decay）在 C++ 中是指当数组被传递给函数时，数组会失去其维度信息，被当作指向其第一个元素的指针处理。这意味着在函数内部，你无法通过数组本身来确定其长度或进行边界检查，因为函数只知道它有一个指向字符的指针。

Q: 如何预防数组衰减呢？

A：
1. 传递数组时同时传递其长度信息。
2. 使用 `std::vector` 或 `std::array` 等容器，这些容器不会发生数组衰减。
3. 如果必须使用指针，确保在传递之前保存数组的长度，并在使用指针时小心处理。


## 头文件
想要使用 `string`，必须引入头文件`<string>`
## 定义 & 初始化 String
使用 `std::string str = "LiuJiaoXiaoYan";`。

## 输入字符串
### std::cin
注意：这种方式适合输入单个字符串，并且字符串中不能有空格。
```cpp
std::string s;
std::cin >> s;
```
### std::getline
注意：可以输入包含空格的一整行字符串。
```cpp
std::string str;
std::getline(std::cin, str);
```
## 容量函数
### 1.字符串长度
- 函数名称：`lenght()` or `size()`。
- 函数功能：返回字符串长度。
```cpp
std::string s = "hello";
std::cout << s.length() << std::endl; // 5
std::cout << s.size() << std::endl; // 5
```
### 2.字符串的容量
- 函数名称：`capacity()`。
- 函数功能：返回字符串容量。
```cpp
std::string s = "hello";
std::cout << s.capacity() << std::endl; // 5
std::string str = s + "world!";
std::cout << str.capacity() << std::endl; // 5
```
## 访问字符串
### 1.下标访问
- 使用：`array[index]`。
- 功能：可以独立地访问字符串中的每一个字符。
```cpp
std::string s = "hello";
std::cout << s[1] << std::endl; // e
```
### 2. 内置函数
- 函数名称：`at()`。
- 函数功能：可以将给定字符串索引位置的字符提取出来。
```cpp
std::string s = "hello";
std::cout << s.at(1) << std::endl; // e
```
## 链接&附加
### 1. 附加 `+`
在 `std::string` 类中重载了 `+`，允许我们将两个字符串连接起来。使用 `+` 运算符拼接字符串时，两个操作数至少有一个必须是 `std::string` 类型的。如果另一个操作数不是字符串，它将被转换为字符串。
```cpp
std::string s = "hello";
s = s + " world!";
std::cout << s << std::endl; // hello world!
s = s + 'A';
std::cout << s << std::endl; // hello world!A
```
### 2. 附加
#### 整个附加
- 函数名称：`str1.append(str2)`。
- 函数功能：可以将一个字符`str2`或者字符串`str2`添加到一个字符串`str1`后面。
```cpp
std::string s = "hello";
std::string s1 = " world!";
s.append(s1); // 将 s1 添加到 s 后面
std::cout << s << std::endl; // hello world!
```
#### 部分附加
- 函数名称：`str1.append(str2, pos, num);`
- 函数功能：可以将字符串`str2`的第 `pos` 位置起(包括 `pos`)，取 `num` 个子字符串，添加到`str1`中。
```cpp
std::string s = "hello ";
std::string s1 = " aaaypbxxx";
s.append(s1, 4, 3);
std::cout << s << std::endl; // hello ypb
```
#### 添加多次
- 函数名称：`str.append(num, c)`。
- 函数功能：可以在`str`后面添加 `num`次字符`c`。
```cpp
std::string s = "hello ";
s.append(3, '!');
std::cout << s << std::endl; // hello !!!
```
#### 范围添加
- 函数名称：`str.append(first, last);`。
- 函数功能：`first`添加字符串的起始位置，`last`添加字符串的结束位置。
```cpp
std::string s = "hello ";
std::string s1 = "aaaypbbbb";
s.append(s1.begin() + 3, s1.begin() + 6);
std::cout << s << std::endl; // hello ypb
```
## 字符串比较
### 1. 操作符 ==
在c++中的`std::string`类中，进行重载了`==`操作符。可以用于比较两个字符串是否相等。当两个字符串的**长度相同**，并且**对应位置的字符都相等**时，这两个字符串被认为是相等的。
```cpp
std::string str1 = "Hello";
std::string str2 = "Hello";
std::string str3 = "World";

// 比较两个相同的字符串
if (str1 == str2) {
std::cout << "str1 and str2 are equal." << std::endl; // 输出 "str1 and str2 are equal."
}

// 比较两个不同的字符串
if (str1 != str3) {
std::cout << "str1 and str3 are not equal." << std::endl; // 输出 "str1 and str3 are not equal."
}

// 比较一个字符串与空字符串
std::string emptyStr;
if (emptyStr == "") {
std::cout << "emptyStr is an empty string." << std::endl; // 输出 "emptyStr is an empty string."
}
```
### 3. 使用函数
- 函数名称：`str1.compare(str2)`。
- 函数功能：可以比较当前字符串与另一个字符串，或者比较当前字符串的一部分与另一个字符串或字符串的一部分。`compare` 函数返回一个整数，用来表示比较结果：如果两个字符串相等，返回 `0`；如果字符串`str1`小于参数字符串`str2`，返回负数；如果字符串`str1`大于参数字符串`str2`，返回正数。
```cpp
std::string str1 = "Hello";
std::string str2 = "World";
std::string str3 = "Hello";

// 比较整个字符串
int result = str1.compare(str2);
std::cout << "Comparison result of str1 and str2: " << result << std::endl; // 输出结果可能是正数或负数
```
同时，`Compare()`函数也有很多重载函数。
## 获取子串
- 函数名称：`substr(pos, len)`。
- 函数功能：用于提取字符串的一部分。它返回一个新的 `std::string` 对象，该对象是原始字符串的一个子字符串，从指定的起始位置（按索引来）开始，具有指定的长度。
```cpp
std::string s = "hello world!";
std::cout << s.substr(2, 3) << std::endl; // llo
```
## 查找子串
- 函数名称：`str1.find(str2)`。
- 函数作用：`find` 函数是 `std::string` 类的成员函数，如果找到了指定的子字符串或字符，它会返回第一个匹配项的索引；如果没有找到，则返回一个特殊的常量 `std::string::npos`。

- 函数名称：`str1.find(str2, pos)`。
- 函数作用：从 `str1`的第 pos 索引开始查找 字符串 `str2`，返回结果和上述一致。
```cpp
std::string str = "Hello, World!";
    
// 查找子字符串 "World"
size_t found = str.find("World");
if (found != std::string::npos)
std::cout << "Found 'World' at index: " << found << std::endl;
else
std::cout << "'World' not found!" << std::endl;
    
// 查找字符 'o'
found = str.find('o');
if (found != std::string::npos)
std::cout << "Found 'o' at index: " << found << std::endl;
else
std::cout << "'o' not found!" << std::endl;
    
// 从特定位置开始查找字符 'o'
found = str.find('o', found + 1); // 从上一个找到的 'o' 之后开始查找
if (found != std::string::npos)
std::cout << "Found 'o' at index: " << found << std::endl;
else
std::cout << "'o' not found!" << std::endl;
```
## 修改字符串
### 插入
- 函数名称：`str1.insert(pos, str2)`。
- 函数功能：在字符串 `str1`的索引为 `pos` 位置上插入字符串 `str2`。
```cpp
std::string str = "Hello";
// 在字符串的索引为 5 的位置插入子字符串
str.insert(5, ", World");
std::cout << str << std::endl; // 输出: Hello, World
```
- 函数名称：`str1.insert(pos, n, c)`。
- 函数功能：在索引为 `pos` 位置连续插入 `n` 次字符 `c`。
```cpp
std::string str = "Hello";
// 在字符串的开头插入字符
str.insert(0, 1, 'X');
std::cout << str << std::endl; // 输出: XHello
```
- 函数名称：`str1.insert(pos, str2, first, last)`。
- 函数功能：将字符串 `str2` 从 迭代器 `first` 到 迭代器 `last` 之间的子字符串，插入到字符串 `str1` 的索引为 `pos` 位置处。
```cpp
std::string str = "Hello";
std::string str1 = "aaa World!ccc";
// 使用迭代器范围插入字符串
str.insert(str.begin() + 5, str1.begin() + 3, str1.end() - 3);
std::cout << str << std::endl; // 输出: Hello, World!
```
### 替换
- 函数名称：`str1.replace(pos, len, str)`。
- 函数功能：将字符串 `str1` 从索引 `pos` 开始，替换 `len` 个字符为子字符串 `str`。
```cpp
std::string str = "Hello World";
// 替换字符串中的第一个字符
str.replace(0, 1, "X");
std::cout << str << std::endl; // 输出: Xello World
```
- 函数名称：`str1.replace(first, last, str2)`。
- 函数功能：用字符串`str2`替换由迭代器范围 `[first, last)`的字符串`str1` 。
```cpp
std::string str = "Hello aaaaa";
// 使用迭代器范围指定要替换的字符序列
str.replace(str.begin() + 6, str.begin() + 11, "World"); 
std::cout << str << std::endl; // 输出: Hello World
```

- 函数名称：`str1.replace(pos, len, n, c)`
- 函数功能：在字符串 `str1` 中从索引 `pos` 开始，替换 `len` 个字符为 `n`个字符 `c`。
```cpp
std::string str = "Hello aaaaa";
// 替换从指定位置开始的特定长度的字符
str.replace(0, 5, 3, 'i');
std::cout << str << std::endl; // 输出: iii aaaaa
```
## 删除
- 函数名称：`str1.erase(pos, len)`。
- 函数功能：删除字符串`str1`中从索引位置 `pos` 开始长度为`len`个字符。
```cpp
std::string str = "Hello World";

// 删除第一个字符
str.erase(0, 1);
std::cout << str << std::endl; // 输出: ello World
```
- 函数名称：`str1.erase(first, last)`。
- 函数功能：删除字符串`str1`中由迭代器范围 `[first, last)` 定义的字符序列。
```cpp
std::string str = "12345";
// 删除由迭代器范围指定的字符序列
str.erase(str.begin() + 3, str.begin() + 5); // 删除 "45"
std::cout << str << std::endl; // 输出: 123
```
- 函数名称：`str1.erase(it)`。
- 函数功能：删除字符串 `str1`中迭代器 `it` 指向的单一字符。
```cpp
std::string str = "12345";

// 删除特定迭代器位置的字符
str.erase(str.begin() + 4); // 删除 '5'
std::cout << str << std::endl; // 输出: 1234
```
## 总结
以上就是常见的在 `std::string` 类中的函数，可以看出好多函数都是基于一个函数进行重载的。但是日常中还有一些对 `string` 类进行操作的常见函数。比如`to_string`。