# [循环嵌套]k的倍数

## 题目描述

给定 $l,r,k$，从小到大输出 $l$ 到 $r$ 之间 $k$ 的倍数，中间用空格隔开。

## 输入格式

输入共 $1$ 行 $3$ 个正整数 $l,r,k$。

## 输出格式

输出 $1$ 行若干个用空格隔开的正整数表示答案。

## 样例 #1

### 样例输入 #1

```
5 16 3
```

### 样例输出 #1

```
6 9 12 15
```

## 提示

#### 样例解释 $1$

在 $5,6,7,8,9,10,11,12,13,14,15,16$ 中，只有 $6,9,12,15$ 是 $3$ 的倍数。

### 数据范围

对于所有数据，$1 \leq l,r,k \leq 1000$，保证 $l\leq r$。