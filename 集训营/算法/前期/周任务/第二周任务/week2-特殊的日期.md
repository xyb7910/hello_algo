# week2-特殊的日期

## 题目背景

**前置知识**：判断质数，判断闰年，数字拼接。

将数字 $123$ 与 $456$ 拼接成一个数字 $123456$ 的方式：$123\times 1000+456=123456$

## 题目描述

小雨的出生日期是 $2000$ 年 $09$ 月 $09$ 日。她惊喜地发现，将年月日拼接在一起得到的数字 $20000909$ 是一个质数。她把这样的日子，称为质数日。

小雨想知道，在 $x(1583\le x\le 9999)$ 年，从 $1$ 月 $1$ 日到 $12$ 月 $31$ 日，一共有多少天是质数日，分别是哪些日期。

特别地，若月和日不足两位，则在前面补 $0$。例如，$2010$ 年 $10$ 月 $9$ 日拼接在一起得到的数字为 $20101009$。

## 输入格式

共 $1$ 个整数 $x$，表示 $x$ 年。

## 输出格式

先输出一个整数 $n$，表示这一年一共有 $n$ 个质数日。

接下来的 $n$ **行**，每行 $2$ 个整数 $m,d$，中间用空格隔开。表示 $x$ 年 $m$ 月 $d$ 日是质数日。

## 样例 #1

### 样例输入 #1

```
2001
```

### 样例输出 #1

```
17
1 27
2 9
2 17
2 23
3 7
3 13
3 23
4 9
5 17
7 1
7 21
8 11
9 17
9 29
10 1
10 7
10 31
```

## 提示

对于 $10\%$ 的数据，$x = 1900$；

对于 $100\%$ 的数据，$1583\le x\le 9999$。