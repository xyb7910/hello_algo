# [分支结构]小A和小B和小C

## 题目描述

小 A 有 $x$ 个苹果，小 B 有 $y$ 个苹果，小 C 有 $z$ 个苹果。

首先，小 A 需要交出自己苹果的一半分给小 B；然后，小 B 需要交出自己苹果的一半分给小 C；最后，小 C 需要交出自己苹果的一半分给小 A。所有的分一半向下保留，即 $7$ 个苹果的一半是 $3$ 个。

请求出三个人的苹果数，同时，再求出三个人苹果数的平均数。请直接使用 cout 输出平均数即可。

## 输入格式

输入共 $1$ 行 $3$ 个正整数，表示 $x,y,z$。

## 输出格式

输出共 $4$ 行。

第 $1$ 行输出 $1$ 个正整数，表示小 A 的苹果数。

第 $2$ 行输出 $1$ 个正整数，表示小 B 的苹果数。

第 $3$ 行输出 $1$ 个正整数，表示小 C 的苹果数。

第 $4$ 行输出 $1$ 个浮点数，表示苹果数的平均数。

## 样例 #1

### 样例输入 #1

```
5 8 17
```

### 样例输出 #1

```
14
5
11
10
```

## 样例 #2

### 样例输入 #2

```
5 8 18
```

### 样例输出 #2

```
14
5
12
10.3333
```

## 提示

#### 样例解释 $1$

$$
(5,8,17)\to(3,10,17)\to(3,5,22)\to(14,5,11)
$$

平均数为 $10$。

#### 样例解释 $2$

$$
(5,8,18)\to(3,10,18)\to(3,5,23)\to(14,5,12)
$$

平均数为 $\frac {31}3\approx 10.3333$。

### 数据范围

对于所有数据，$x,y,z\leq 100$。