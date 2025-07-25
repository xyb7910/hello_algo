# week9-爬格子

## 题目描述

地上有一个长度 $n$，宽度为 $2$ 的表格组成的跳格子。第 $i$ 行第 $j$ 列的格子，有权值 $a_{i,j}$。其中，$1\le i \le n$，$1\le j \le 2$。

游戏开始时，你在第 $1$ 行第 $1$ 列的位置。接下来的每一步，假设当前的位置是在第 $i$ 行第 $j$ 列，你都有以下两种走法：

- 往前走 $a_{i,j}$ 格。也就是跳到第 $i+a_{i,j}$ 行第 $j$ 列；
- 往左或者往右一格。也就是第 $i$ 行不变；如果原来在第 $1$ 就会变为第 $2$ 列，如果原来在第 $2$ 就会变为第 $1$ 列。在这种情况下，上一步不可以是往左或者往右移动。也就是说，不能往左移动后立刻往右移动，往右移动后立刻向左移动。

一但当前位置跳出了格子（也就是行数 $i$ 大于 $n$）时，游戏结束。请问从游戏开始到游戏结束，一共有多少种走法？结果对 $10037$ 取余数。

## 输入格式

第一行输入一个整数 $n$。

接下来 $n$ 行，每行两个整数，分别表示 $a_{i,1}$ 和 $a_{i,2}$。

## 输出格式

一行，一个整数，表示方案数对 $10037$ 取余数的结果。

## 样例 #1

### 样例输入 #1

```
4
1 2
2 1
2 4
1 3
```

### 样例输出 #1

```
6
```

## 提示

## 样例解释

一共有 $6$ 种走法。下面用 $(i,j)$ 表示第 $i$ 行第 $j$ 列。

1. $(1,1)$→$(2,1)$→$(4,1)$→跳出。
2. $(1,1)$→$(2,1)$→$(4,1)$→$(4,2)$→跳出
3. $(1,1)$→$(1,2)$→$(3,2)$→跳出
4. $(1,1)$→$(1,2)$→$(3,2)$→$(3,1)$→跳出
5. $(1,1)$→$(2,1)$→$(2,2)$→$(3,2)$→跳出
6. $(1,1)$→$(2,1)$→$(2,2)$→$(3,2)$→$(3,1)$→跳出




## 数据范围

对于 $30\%$ 的测试数据满足 $n\le 100$，$a_{i,j}\le 10$。

对于另外 $30\%$ 的测试数据满足 $a_{i,2}=1$。

对于所有测试数据满足 $1 \le n \le 10^5$，$1 \le a_{i,j}\le 1000$。