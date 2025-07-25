# week6-排队

## 题目描述

有 $n$ 名小朋友排队，编号为 $1$ 到 $n$。现在已知每个人后面的同学编号（排在最后一个小朋友的后面的同学编号记作 $0$）。请根据这些信息，从前到后输出队伍中的每个人的编号。

## 输入格式

第一行输入一个整数 $n$，表示小朋友的数量。

接下来一行，输入 $n$ 整数，表示这个小朋友后面同学的编号。

## 输出格式

一行 $n$ 个整数，表示队伍中每个小朋友的编号，数字之间用空格隔开。

## 样例 #1

### 样例输入 #1

```
3
2 0 1
```

### 样例输出 #1

```
3 1 2
```

## 提示

### 样例解释

可以发现，没有一个同学的后面是 3，所以小朋友 3 一定是排在最开头的。小朋友 3 的后面同学是小朋友 1，小朋友 1 的后面同学是小朋友 2，小朋友 2 的后面没有其他小朋友，说明他是在队伍的末端，因此队伍的顺序应该是 3->1->2。

### 数据范围

对于 $30\%$ 的测试数据，$n\le 20$；

对于 $100\%$ 的测试数据，$1\le n\le 10^3$；