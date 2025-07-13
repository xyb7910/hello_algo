
[题目链接](https://atcoder.jp/contests/abc377/tasks/abc377_f)
### Problem Statement

There is a grid of $N^2$ squares with $N$ rows and $N$ columns. Let $(i,j)$ denote the square at the $i$\-th row from the top $(1\leq i\leq N)$ and $j$\-th column from the left $(1\leq j\leq N)$.

Each square is either empty or has a piece placed on it. There are $M$ pieces placed on the grid, and the $k$\-th $(1\leq k\leq M)$ piece is placed on square $(a_k,b_k)$.

You want to place your piece on an **empty square** in such a way that it **cannot be captured by any of the existing pieces**.

A piece placed on square $(i,j)$ can capture pieces that satisfy any of the following conditions:

-   Placed in row $i$
-   Placed in column $j$
-   Placed on any square $(a,b)\ (1\leq a\leq N,1\leq b\leq N)$ where $i+j=a+b$
-   Placed on any square $(a,b)\ (1\leq a\leq N,1\leq b\leq N)$ where $i-j=a-b$

For example, a piece placed on square $(4,4)$ can capture pieces placed on the squares shown in blue in the following figure:

![](https://img.atcoder.jp/abc377/b0741e9d4d5765a5eeaf1b7f03310f3c.png)

How many squares can you place your piece on?

### 中文题意
#### 问题陈述

有一个由 $N^2$ 个正方形组成的网格，网格中有 $N$ 行和 $N$ 列。让 $(i,j)$ 表示从上面 $(1\leq i\leq N)$ 起第 $i$ 行，从左边 $(1\leq j\leq N)$ 起第 $j$ 列的正方形。

每个方格要么是空的，要么有一个棋子放在上面。网格上有 $M$ 个棋子， $k$ - $(1\leq k\leq M)$ 个棋子被放在了 $(a_k, b_k)$ 个方格上。

您想要将棋子放在**个空格**上，使其**不能被任何现有棋子吃掉**。

放置在位置 $(i,j)$ 上的棋子可以吃掉满足以下任何条件的棋子：

- 置于行 $i$ 中
- 放在 $j$ 列中
- 放置在 $i+j=a+b$ 所在的任意位置 $(a,b)\\ (1\leq a\leq N,1\leq b\leq N)$ 上
- 放置在 $i-j=a-b$ 所在的任意位置 $(a,b)\\ (1\leq a\leq N,1\leq b\leq N)$ 上

例如，放在 $(4,4)$ 位置上的棋子可以吃掉下图中蓝色所示位置上的棋子：

![](https://img.atcoder.jp/abc377/b0741e9d4d5765a5eeaf1b7f03310f3c.png)

您可以将棋子放在几个位置上？
### Constraints

-   $1\leq N\leq10^9$
-   $1\leq M\leq10^3$
-   $1\leq a_k\leq N,1\leq b_k\leq N\ (1\leq k\leq M)$
-   $(a_k,b_k)\neq(a_l,b_l)\ (1\leq k\lt l\leq M)$
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:


$N$ $M$

$a_1$ $b_1$

$a_2$ $b_2$

$\vdots$

$a_M$ $b_M$



### Output

Print the number of empty squares where you can place your piece without it being captured by any existing pieces.

### Sample Input 1

```
8 6
1 4
2 1
3 8
4 5
5 2
8 3
```
### Sample Output 1

```
2
```

The existing pieces can capture pieces placed on the squares shown in blue in the following figure:

![](https://img.atcoder.jp/abc377/49766c3613371e99673e5722bd64ad58.png)

Therefore, you can place your piece on only two squares: squares $(6,6)$ and $(7,7)$.

### Sample Input 2

```
1000000000 1
1 1
```

### Sample Output 2

```
999999997000000002
```

Out of $10^{18}$ squares, the squares that cannot be used are: squares in row $1$, squares in column $1$, and squares $(1,1)$, $(2,2)$, $\ldots$, $(10^9,10^9)$, totaling $3\times10^9-2$ squares.

Note that the answer may be $2^{32}$ or greater.

### Sample Input 3

```
20 10
1 4
7 11
7 15
8 10
11 6
12 5
13 1
15 2
20 10
20 15
```

### Sample Output 3

```
77
```

### 解法

这道题目与前两道题目类似，只不过是禁止放棋子的位置略有不同。本次是一个“米字形”，这里的话，我们的同样也采用集合去重的方式将所有不能放棋子的位置存起来。最后使用棋盘规模 - 集合大小即可。

定义是个集合`hori`, `vert`, `diag`, `anti_diag`，分别表示水平线，垂直线，对角线，反对角线。

首先将所有的水平线和对角线的元素加入到集合中；再将对角线加入到集合中,使用`x - y`表示对角线，使用`x + y`表示副对角线。

之后每一步考虑，加入当前的对角线和副对角线会有多少个新增的不能放棋子的点。最后再加入副对角线的时候，也要考虑副对角线和对角线的交点情况。

```cpp
typedef long long LL;
int n, m;
// 分别表示水平线，垂直线，对角线，副对角线
set<int> hori, vert, diag, anti_diag;

void solved() {
    /* your code */
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        hori.insert(x);
        vert.insert(y);
        diag.insert(x - y);
        anti_diag.insert(x + y);
    }

  	// 初步答案 = 棋盘规模 - 不能放棋子的位置
    LL ans = (LL)(n - hori.size()) * (n - vert.size());

    // 加入主对角线之后，考虑会有多少个新增加的不能放棋子的位置
    for (auto d : diag) {
        set<int> cross_x;
        for (auto x : hori) {
            int y = x - d;
            if(1 <= y && y <= n) {
                cross_x.insert(x);
            }
        }

        for (auto y : vert) {
            int x = d + y;
            if(1 <= x && x <= n) {
                cross_x.insert(x);
            }
        }

        int cross_num = cross_x.size();
        int d_len = n - abs(d);
        ans -= d_len - cross_num;
    }

    // 加入副对角线之后，考虑会有多少个新增的不能放棋子的位置
    for (auto e : anti_diag) {
        set<int> cross_x;
        for (auto x : hori) {
            // e = x + y ==> y = e - x;
            int y = e - x;
            if(1 <= y && y <= n) {
                cross_x.insert(x);
            }
        }   

        for (int y : vert) {
            // e = x + y ==> x = e - y;
            int x = e - y;
            if (1 <= x && x <= n) {
                cross_x.insert(x);
            }
        }

        for (auto d : diag) {
            // 枚举每一条对角线，检查两者是都相交，并记录交点的 x 坐标
            int x = (d + e) / 2;
            int y = (e - d) / 2;
            if ((d + e) % 2 == 0 && 1 <= x && x <= n && 1 <= y && y <= n) {
                cross_x.insert(x);
            } 
        }
        int cross_num = cross_x.size();
        int e_len = n - abs(e - (n + 1));
        ans -= e_len - cross_num;
    }
    cout << ans << endl;
} 
```
### 总结

这三期的题，都在锻炼与棋盘有关的题目训练，今天是最后一期了，重点学习主对角线和副对角线如何表示，以及新增点后的情况。
