# week4-[字符数组]英语作文

## 题目背景

abslime正在写一篇英语作文，但是他不小心在很多单词之间插入了过多的空格，现在他希望把多余的空格去掉，使得相邻两个单词之间只有恰好一个空格，并且希望知道他多输入了多少个空格。

## 题目描述

给定abslime写的英语作文，其中仅包含若干个单词和空格（为了简化起见，这里没有考虑标点符号）。每个单词仅由大小写英文字母组成，且相邻两个单词之间至少有一个空格。需要输出去掉多余空格的英语作文，以及abslime多输入了多少个空格。

## 输入格式

输入一行，为一个仅包含英文字母和空格的字符串，表示abslime写的英语作文（保证第一个字符和最后一个字符一定不是空格）。

## 输出格式

输出两行，第一行为去掉多余空格的英语作文。第二行为一个整数，表示abslime多输入了多少个空格。

## 样例 #1

### 样例输入 #1

```
Suppose   you are going  to spend  a whole   month in     a  remote  island
```

### 样例输出 #1

```
Suppose you are going to spend a whole month in a remote island
12
```

## 样例 #2

### 样例输入 #2

```
To begin    with   we   should    make clear  of   the conception of innovative      capability
```

### 样例输出 #2

```
To begin with we should make clear of the conception of innovative capability
18
```

## 样例 #3

### 样例输入 #3

```
you      shall not    pass
```

### 样例输出 #3

```
you shall not pass
8
```

## 提示

### 数据范围

对于所有输入数据，输入字符串的总长度不超过 $2000$。