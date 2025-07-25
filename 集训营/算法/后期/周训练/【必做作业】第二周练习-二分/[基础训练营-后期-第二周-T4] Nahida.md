# [基础训练营-后期-第二周-T4] Nahida

## 题目描述

在遥远的西西艾佛大陆上，有 $N$ 座线性排列 **（从 $1$ 编号到 $N$）** 的魔法基站。魔法基站共有两种属性，为草属性（用 `A` 表示）与火属性（用 `B` 表示）。

Nahida 可以在魔法基站间进行传送，**传送不消耗时间**：

- 从 $L$ 号基站传送到 $R$ 号基站（$L<R$），要求 $[L,R-1]$ 的基站全都是草元素。消耗 $p$ 点灵力。
- 从 $L$ 号基站传送到 $R$ 号基站（$L<R$），要求 $[L,R-1]$ 的基站全部是火元素。消耗 $q$ 点灵力。

Nahida 一开始在 $0$ 号点，必须先步行一段路到达基站，然后开始传送，一旦 Nahida 开始传送，她就不能走路步行了。如果 Nahida 选择步行走到 $i$ $(1\leqslant i \leqslant N)$ 号基站，会消耗 $i$ 单位的时间。

现在 Nahida 有 $M$ 单位灵力，请问 Nahida 最少消耗多少单位时间，可以从 $0$ 号点出发，到达 $N$ 号基站。

## 输入格式

输入共两行。

输入的第一行为四个整数 $N,p,q,M$。

输入的第二行为长度为 $N$ 的字符串，由 `AB` 组成，第 $i$ 个字符代表第 $i$ 号基站的类型。

## 输出格式

输出一行一个整数，代表 Nahida 最小消耗的时间。

## 样例 #1

### 样例输入 #1

```
2 2 2 1
BB
```

### 样例输出 #1

```
2
```

## 样例 #2

### 样例输入 #2

```
6 2 1 1
ABABAB
```

### 样例输出 #2

```
6
```

## 样例 #3

### 样例输入 #3

```
10 3 2 8
AABBBBAABB
```

### 样例输出 #3

```
3
```

## 提示

对于 $30\%$ 的数据，$2 \le N \le 5000$；  
对于 $100\%$ 的数据，$1 \le p,q,M \le 10^5$，$2 \le N \le 10^5$。

**样例解释：**  
对于样例 $3$，先步行走到 $3$ 号基站，然后使用火元素传送到达 $7$ 号基站，再使用草元素传送到达 $9$ 号基站，最后使用火元素传送到达 $10$ 号基站。