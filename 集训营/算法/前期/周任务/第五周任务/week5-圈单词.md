# week5-圈单词

## 题目描述

abslime和「QQ红包」面前有一个 $n$ 行 $m$ 列的字符矩阵 $S$。字符矩阵 $S$ 第 $i$ 行 第 $j$ 列的字符记为 $S_{i,j}$。为了方便，用 $(i,j)$ 表示矩阵第 $i$ 行第 $j$ 列的位置。

abslime和「QQ红包」打算在这个字符矩阵上玩一个游戏。首先abslime在 $S$ 中选择出一个位置 $(r,c)$，接着「QQ红包」在 $S$ 中选择出一个和 $(r,c)$ 在同一直线上（同一行，同一列，同一45度斜线）的位置 $(x,y)$。这样的话，矩阵 $S$ 从 $(r,c)$ 到 $(x,y)$ 这条直线上的字符依次连接起来将形成一个字符串 $str$。abslime和「QQ红包」需要尽可能快地将 $str$ 计算出来。如果谁又快又准地将 $str$ 计算出来，就可以获得对方发的QQ红包。

这个游戏还需要一个裁判。请编写一个裁判程序，对于给定的字符矩阵 $S$，位置 $(r,c)$ 和 $(x,y)$，请将从 $(r,c)$ 到 $(x,y)$ 这条直线上的字符依次连接得到的字符串 $str$ 输出出来。

## 输入格式

输入第一行包括两个整数 $n$ 和 $m$，表示矩阵 $S$ 的行数和列数。

接下来 $n$ 行，每行 $m$ 个字符，表示字符矩阵 $S$。

接下来两行，每行两个整数，分别表示abslime选择的位置 $(r,c)$ 和「QQ红包」选择的位置 $(x,y)$。

## 输出格式

输出一行，为一个字符串 $str$。

## 样例 #1

### 样例输入 #1

```
4 5
abcde
fghij
klmno
pqrst
2 3
4 3
```

### 样例输出 #1

```
hmr
```

## 样例 #2

### 样例输入 #2

```
7 8
afnuhusa
qazxswed
uehqpzlm
fueqmzog
qwertyui
zxcvbnml
wsxijnde
4 7
4 2
```

### 样例输出 #2

```
ozmqeu
```

## 样例 #3

### 样例输入 #3

```
7 8
afnuhusa
qazxswed
uehqpzlm
fueqmzog
qwertyui
zxcvbnml
wsxijnde
2 3
6 7
```

### 样例输出 #3

```
zqmym
```

## 样例 #4

### 样例输入 #4

```
7 8
afnuhusa
qazxswed
uehqpzlm
fueqmzog
qwertyui
zxcvbnml
wsxijnde
7 2
3 6
```

### 样例输出 #4

```
scrmz
```

## 样例 #5

### 样例输入 #5

```
2 3
abc
fgh
1 2
1 2
```

### 样例输出 #5

```
b
```

## 提示

对于 $30\%$ 的数据满足：$1 \le n,m\le 10$。

对于 $60\%$ 的数据满足：$1 \le n,m\le 100$。

对于 $100\%$ 的数据满足：$1 \le n,m\le 1000,1\le r,x\le n,1 \le c,y \le m$，字符矩阵 $S$ 均由小写英文字母构成，保证 $(r,c)$ 和 $(x,y)$ 在同一直线上（同一行，同一列，同一45度斜线）。