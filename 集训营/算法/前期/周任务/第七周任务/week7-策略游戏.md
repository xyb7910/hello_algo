# week7-策略游戏

## 题目描述

Aya 在玩一个策略游戏。在游戏中，他要主动出击，攻打对方的军队。对方的军队可以视作一个 $n$ 行 $m$ 列的矩阵，军队中由 $1$ 表示士兵，由 $0$ 表示后勤。

Aya 有 $k$ 支军队，每一支军队可以攻打敌方一行的军队，但是一行只能安排一支军队。Aya 认为，攻打军队要从弱的打起，逐步蚕食对方的兵力。因此，他制定了一个方案判断敌方每一行军队的强弱：

- 如果第 $i$ 行的士兵比第 $j$ 行少，或者第 $i$ 行的士兵与第 $j$ 行数量相等但是 $i<j$，则第 $i$ 行的战斗力比第 $j$ 行更弱。

Aya 希望知道他的 $k$ 支军队要攻打敌方军队的哪几行。请你，她的军师，告诉她。

## 输入格式

第一行输入三个正整数 $n,m,k$。

第二行开始，往下 $n$ 行，每行输入 $m$ 个整数 $0$ 或 $1$。

## 输出格式

一行，输出 $k$ 个正整数，表示从战斗力的弱到强输出要攻打地方军队的哪几行。

## 样例 #1

### 样例输入 #1

```
5 5 3
1 0 1 1 0
0 1 1 0 1
1 1 1 1 0
1 1 0 0 0
0 1 0 0 0
```

### 样例输出 #1

```
5
4
1
```

## 提示

**【数据范围】**

对于 $30\%$ 的数据，$1 \leq n,m,k \leq 10$；

另有 $30\%$ 的数据，$k=1$；

对于所有数据，$1 \leq n,m \leq 1000$，$1 \leq k \leq n$。