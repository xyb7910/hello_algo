# week11-[模拟]消除

## 题目描述

给定一个初始为空的集合，一共会进行 $n$ 次操作，每次操作会向这个集合里添加一个数，如果这个集合里面已经有这个数了则把它删除。

问操作完之后集合内还有哪些数。

## 输入格式

第一行一个正整数 $n$

第二行 $n$ 个非负整数，第 $i$ 个数 $a_{i}$ 表示第 $i$ 次尝试加进去的数。

## 输出格式

共一行，按从小到大的顺序输出集合中的数。

## 样例 #1

### 样例输入 #1

```
10
0 4 1 0 1 0 0 2 1 4
```

### 样例输出 #1

```
1 2
```

## 提示

$1\leq n\leq 100,0\leq a_{i}\leq 100$