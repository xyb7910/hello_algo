[题目链接]([F - Add One Edge 2 (atcoder.jp)](https://atcoder.jp/contests/abc378/tasks/abc378_f))
### Problem Statement

You are given a tree with $N$ vertices. The $i$\-th edge $(1 \leq i \leq N-1)$ connects vertices $u_i$ and $v_i$ bidirectionally.

Adding one undirected edge to the given tree always yields a graph with exactly one cycle.

Among such graphs, how many satisfy all of the following conditions?

-   The graph is simple.
-   All vertices in the cycle have degree $3$.
### 中文题意
#### 问题陈述

给你一棵有 $N$ 个顶点的树。 $i -th$ 边 $(1 \leq i \leq N-1)$ 双向连接顶点 $u_i$ 和 $v_i$ 。

在给定的树上添加一条无向边会得到一个有一个循环的图。

在这些图中，有多少个满足以下所有条件？

- 图很简单。
- 循环中的所有顶点都有度数 $3$ 。
### Constraints

-   $3 \leq N \leq 2 \times 10^5$
-   $1 \leq u_i, v_i \leq N$
-   The given graph is a tree.
-   All input values are integers.
### Input

The input is given from Standard Input in the following format:
$N$
$u_1$ $v_1$
$u_2$ $v_2$
$\vdots$
$u_{N-1}$ $v_{N-1}$
### Output

Print the answer.

### Sample Input 1

```
6
1 2
2 3
3 4
4 5
3 6
```

### Sample Output 1

```
1
```
Adding an edge connecting vertices $2$ and $4$ yields a simple graph where all vertices in the cycle have degree $3$, so it satisfies the conditions.

### Sample Input 2

```
7
1 2
2 7
3 5
7 3
6 2
4 7
```
### Sample Output 2

```
0
```

There are cases where no graphs satisfy the conditions.

### Sample Input 3

```
15
1 15
11 14
2 10
1 7
9 8
6 9
4 12
14 5
4 9
8 11
7 4
1 13
3 6
11 10
```
### Sample Output 3

```
6
```

### 解法

考虑，新增加一条边必然会使得所连接的两个点的度数$+ 1$。现在要求环上的所有节点的度数都为 $3$ ，在这里我们可以对目前树中部分度数为3的点视为一个连通块。然后我们对于每一个顶点，依次统计一下与其相连的节点度数是否为$2$。如果是$2$，将 `cnt` 的数量 $+1$ ，因为每次连接成环的话，是选择其中两个顶点，那么最后的答案数为$C_{n}^{2}$ 。
```cpp
typedef long long LL;
std::vector<int> G[N];
int deg[N];
bool visit[N];
LL cnt, ans;

void dfs(int v, int fa = 0) {
	if(deg[v] != 3) {
		// v是一个周边的点
		cnt += (deg[v] == 2);
		return ;
	}

	visit[v] = 1;
	for (auto x : G[v]) {
		if(x == fa) continue;
		dfs(x, v);
	}
}

void solved() {
	/* your code */
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
		deg[u] ++, deg[v] ++;
	}

	for (int i = 1; i <= n; i ++) {
		//找度数为3的连通块
		if(deg[i] != 3) continue;	
		if(visit[i]) continue;
		cnt = 0;
		dfs(i);
		ans += 1LL * cnt * (cnt - 1) / 2; 
	}
	cout << ans << endl;
}
```
### 总结
本道题目，看似是一个树的题目。我们将其转化为了一个`dfs` 型的联通块计算题目。然后使用[[组合]]计数即可。