# week3-人气投票

## 题目描述

某游戏为了进行分析，想要进行一次音乐人气投票。

开发商会用一首音乐询问 $n$ 个玩家，每位玩家都自然会对这首音乐评一个好感度 $a_i$。为了做出好看的报表数据，开发商有 $m$ 次操作。每次操作形如：

- `1 x y z` 表示将好感度**范围**在 $[a_x,a_y]$ 中的所有好感度修改为 $z$。注意若 $a_x>a_y$，则是将将好感度范围在 $[a_y,a_x]$ 中的所有好感度修改为 $z$。若 $a_x$ 与 $a_y$ 相等则不用做任何操作。

- `2 x z` 表示将整个序列中所有的 $a_x$ **这个好感度**增加 $z$。

- `3 x y` 表示求出序列中，求出好感度在 $[a_x,a_y]$ 中所有数字的平均值，**向下取整**。若 $a_x>a_y$，则是求出好感度在 $[a_y,a_x]$ 中所有数字的平均值向下取整。若 $a_x$ 与 $a_y$ 相等，输出 $0$。

**说明：**

各位同学可能没有相关知识。我们定义一个数字 $x$ 在范围 $[a,b]$（其中 $a<b$），则意思是 $a \leq x \leq b$，注意是**小于等于**符号而并非小于符号。例如：$3$ 在 $[3,5]$ 范围内，$4$ 在$[3,5]$ 范围内而 $9$ 不在$[3,5]$ 范围内。

**本题题意可能较难理解，可以查阅样例说明进行理解。**

## 输入格式

第一行输入两个整数 $n$ 和 $m$，意思如题所示。

第二行输入 $n$ 个数字 $a_i$，表示第 $i$ 个玩家的好感度。

第三行开始，一共 $m$ 行，每一行可能会输入 $3$ 或者 $4$ 个数字。

如果第一个数字是 $1$，后面就再输入 $3$ 个数字 $x,y,z$，表示将 $[a_x,a_y]$ 中的所有好感度修改为 $z$。

如果第一个数字是 $2$，后面就再输入 $2$ 个数字 $x,z$，表示将 $a_x$ 这个好感度增加 $z$。

如果第一个数字是 $3$，后面就再输入 $2$ 个数字 $x,y$，表示求出 $[a_x,a_y]$ 中所有数字的平均值，向下取整。

## 输出格式

对于每个第一个数字是 $3$ 的操作，输出一行，表示这个向下取整的平均值。

## 样例 #1

### 样例输入 #1

```
5 6
3 5 8 1 2
1 2 3 5
3 1 4
2 3 5
3 3 5
1 1 4 9
3 2 3
```

### 样例输出 #1

```
2
6
0
```

## 样例 #2

### 样例输入 #2

```
3 3
1000000000 10 10
2 1 1000000000
2 1 1000000000
3 1 2
```

### 样例输出 #2

```
1000000006
```

## 提示

样例 $1$ 解释：

第一次操作，是把原数列中，在 $[a_2,a_3]$ 这个范围的所有数字变为 $5$，即把原数列中在 $[5,8]$ 的所有数字变为 $5$，故原数列变为 3 5 5 1 2。

第二次操作，是输出数列中，在 $[a_1,a_4]$ 这个范围的所有数字的平均值，即 $[1,3]$ 内的所有数字的平均数，原数列中只有 $1,2,3$ 满足，故平均值为 2。

第三次操作，是把数列中所有等于 $a_3$ 的值加上 $5$，故数列变为 3 10 10 1 2。

经过第四次操作后，数列还是 3 10 10 1 2

经过第五次操作后，数列变为 9 10 10 9 9

经过第六次操作后，数列还是 9 10 10 9 9

数据规模如下表。

特殊性质 $1$ 若为钩，则表示没有第一个数字为 $1$ 的操作，对于特殊性质 $2$，$3$ 同理。

| 数据点编号 |     $n$     |     $m$     | 特殊性质 1 | 特殊性质 2 | 特殊性质 3 |
| :--------: | :---------: | :---------: | :--------: | :--------: | :--------: |
|    $1$     | $\leq 3000$ | $\leq 3000$ |            |            | $\sqrt{}$  |
|    $2$     |  $\leq 10$  |     $0$     |            |            |            |
|    $3$     |  $\leq 10$  |    $10$     |            |            |            |
|    $4$     | $\leq 1000$ | $\leq 1000$ | $\sqrt{}$  | $\sqrt{}$  |            |
|    $5$     | $\leq 1000$ | $\leq 1000$ | $\sqrt{}$  |            |            |
|    $6$     | $\leq 1000$ | $\leq 1000$ | $\sqrt{}$  |            |            |
|    $7$     | $\leq 1000$ | $\leq 1000$ |            | $\sqrt{}$  |            |
|    $8$     | $\leq 1000$ | $\leq 1000$ |            |            |            |
|    $9$     | $\leq 3000$ | $\leq 3000$ |            |            |            |
|    $10$    | $\leq 3000$ | $\leq 3000$ |            |            |            |



数据约定：

对于第 $1-8$ 组数据，对于输入时的所有 $a_i$ 满足 $1 \leq a_i \leq 10^5$，所有的 $z$ 满足 $1 \leq z \leq 10^5$。

对于所有数据，输入时的所有 $a_i$ 满足 $1 \leq a_i \leq 10^9$，所有的 $z$ 满足 $1 \leq z \leq 10^9$。

数据保证，$1 \leq x,y \leq n$。