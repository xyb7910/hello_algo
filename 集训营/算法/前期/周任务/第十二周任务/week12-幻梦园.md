# week12-幻梦园

## 题目背景

那个小姑娘慢慢走到森林中。偶尔走到森林下，因为森林的华盖彻底遮挡住天空，翠绿的树叶犹如密布的云。噢！偶尔还走到森林上，因为地面上布满着树根！别绊着，小姑娘，别绊着。现在……她走到了森林外。

## 题目描述

定义一个长度为 $n$ 的序列 $a$ 的权值为

$a_1 \times n + a_2 \times (n-1) + ... + a_i \times (n-i) + ... +a_n \times  1$。

现在有一个初始为空的数组 $A$，依次添加 $n$ 个数字，每次添加数字的时候都是将数字放在当前数组的末尾，添加完每个数字之后请输出当前数组的权值对 $ 998244353$ 取模后的结果。

## 输入格式

第一行包括一个整数 $n$，表示要添加数字的个数。

第二行包括 $n$ 个整数，按照添加先后顺序表示要添加的数字 $A_1,A_2...A_n$。

## 输出格式

输出仅一行，包含 $n$ 个整数，使用空格分隔，依次表示添加完第 $1,2...,n$ 个数字后数组的权值对 $998244353$ 取模后的结果。

## 样例 #1

### 样例输入 #1

```
4
7 3 2 5
```

### 样例输出 #1

```
7 17 29 46
```

## 提示

### 数据范围

对于 $60\%$ 的数据满足：$1 \le n \le 10^3$，$1 \le A_i \le 10^5$；

对于 $100\%$ 的数据满足：$1 \le n \le 10^5$，$1 \le A_i \le 10^5$。