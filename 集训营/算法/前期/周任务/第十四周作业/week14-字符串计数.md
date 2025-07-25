# week14-字符串计数

## 题目描述

从一个空字符串开始，每次可以在字符串尾部添加一个字符 $0$，或者可以在字符串尾部添加连续 $k$ 个字符 $1$。

求采用上述这两种操作，可以得到多少种不同的长度为 $n$ 的字符串。

## 输入格式

输入一行，包括两个整数 $n$ 和 $k$。

## 输出格式

输出一行，只包括一个整数，表示字符串数目对 $100000007$ 取模的结果。

## 样例 #1

### 样例输入 #1

```
5 1
```

### 样例输出 #1

```
32
```

## 样例 #2

### 样例输入 #2

```
5 2
```

### 样例输出 #2

```
8
```

## 样例 #3

### 样例输入 #3

```
5 3
```

### 样例输出 #3

```
4
```

## 样例 #4

### 样例输入 #4

```
10 3
```

### 样例输出 #4

```
28
```

## 样例 #5

### 样例输入 #5

```
5 5
```

### 样例输出 #5

```
2
```

## 样例 #6

### 样例输入 #6

```
10 4
```

### 样例输出 #6

```
14
```

## 提示

对于 $10\%$ 的数据，$1 \le n, k \le 5$；

对于 $20\%$ 的数据，$1 \le n, k \le 10$；

对于 $50\%$ 的数据，$1 \le n, k \le 30$；

对于 $70\%$ 的数据，$1 \le n, k \le 1000$；

对于所有数据，$1 \le n, k \le 1000000$。