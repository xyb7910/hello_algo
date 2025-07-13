[题目链接](https://atcoder.jp/contests/abc378/tasks/abc378_e)
### Problem Statement

You are given a sequence $A = (A_1, A_2, \dots, A_N)$ of $N$ non-negative integers, and a positive integer $M$.

Find the following value:

$$
 \sum_{1 \leq l \leq r \leq N} \left( \left(\sum_{l \leq i \leq r} A_i\right) \mathbin{\mathrm{mod}} M \right). 
$$

Here, $X \mathbin{\mathrm{mod}} M$ denotes the remainder when the non-negative integer $X$ is divided by $M$.

#### 问题陈述

给你一个由 $N$ 个非负整数组成的序列 $A = (A_1, A_2, \dots, A_N)$和一个正整数 $M$ 。

求下列数值：

$$
 \sum_{1 \leq l \leq r \leq N} \left( \left(\sum_{l \leq i \leq r} A_i\right) \mathbin{\mathrm{mod}} M \right). 
$$
这里， $X \mathbin{\mathrm{mod}} M$ 表示非负整数 $X$ 除以 $M$ 的余数。

### Constraints

-   $1 \leq N \leq 2 \times 10^5$
-   $1 \leq M \leq 2 \times 10^5$
-   $0 \leq A_i \leq 10^9$

### Input

The input is given from Standard Input in the following format:

```
N M
A1 A2 ... AN
```

### Output

Print the answer.
### Sample Input 1

```
3 4
2 5 0
```
### Sample Output 1

```
10
```

-   $A_1 \mathbin{\mathrm{mod}} M = 2$
-   $(A_1+A_2) \mathbin{\mathrm{mod}} M = 3$
-   $(A_1+A_2+A_3) \mathbin{\mathrm{mod}} M = 3$
-   $A_2 \mathbin{\mathrm{mod}} M = 1$
-   $(A_2+A_3) \mathbin{\mathrm{mod}} M = 1$
-   $A_3 \mathbin{\mathrm{mod}} M = 0$

The answer is the sum of these values, $10$. Note that the outer sum is not taken modulo $M$.

### Sample Input 2

```
10 100
320 578 244 604 145 839 156 857 556 400
```
### Sample Output 2

```
2736
```


### 解法
这道题目着重考察[[树状数组]]，首先我们先从[[前缀和]]出发。

数组中前 $i$ 项和为 $s[i]$  。

对题目中计算式子进行变化。
$$\sum_{l\leq i \leq r} A_i = s[r] - s[l - 1]$$


接下来，考虑对$M$ 取余操作。

$$
(s[r]-s[l-1]) \bmod M=\left\{\begin{array}{ll}
s[r]-s[l-1], & s[r] \geq s[l-1] \\
s[r]-s[l-1]+M, & s[r]<s[l-1]
\end{array}\right.
$$
从上述公式可以看出，加 $or$ 不加 $M$ 取决于 $s[r]$ 与 $s[l - 1]$ 的大小情况。
这里，我们将 $s[r]$ 与 $s[l - 1]$ 的大小情况定义为一个命题。
那么，公式可以改写为：
$$(s[r]-s[l-1]) \bmod M=s[r]-s[l-1]+M *[s[r]<s[l-1]]$$ 将公式带入原题中可得：
$$
\begin{aligned}
 \sum_{1 \leq l \leq r \leq N} \left( \left(\sum_{l \leq i \leq r} A_i\right) \mathbin{\mathrm{mod}} M \right)
 & =\sum_{1 \leq l \leq r \leq N} s[r]-s[l-1]+M *[s[r]<s[l-1]] \\
& =\sum_{1 \leq l \leq r \leq N}(s[r]-s[l-1])+\sum_{1 \leq l \leq r \leq N} M *[s[r]<s[l-1]] \\
& =\sum_{1 \leq l \leq r \leq N} s[r]-\sum_{1 \leq l \leq r \leq N} s[l-1]+M \sum_{1 \leq l \leq r \leq N}[s[r]<s[l-1]] \\
& =\sum_{r=1}^{n} s[r] \times r-\sum_{l=1}^{n} s[l-1] \times(n-l+1)+M \sum_{1 \leq l \leq r \leq N}[s[r]<s[l-1]]
\end{aligned}\\
$$
对于公式最后一行，进行一下解释。

从倒数第二行的公式可以看出来，在范围从$[1, N]$ 之间，我们要计算$s[r]$时，可以看出每个$s[r]$被计算$r$次，每个$s[l - 1]$ 被计算$n - l - 1$ 次。所以，倒数第二行公式可以简化为最后一行公式。然后再看一下倒数第二行的最后一个命题，$l - 1$ 是必然小于 $r$ 的，但是呢？$s[r] < s[l -1]$ ，这种形式很符合逆序对，所以只需要统计逆序对的个数，然后在乘上 $M$ 就可以了。

这里，我们已经将公式化为最简了，接下来，看看代码如何编写吧。
```cpp
typedef long long LL;
int n, m;
int a[N], s[N];

struct BIT{
	#define lowbit(x) ((x) & (-(x)))
	int tree[N];

	void add(int p, int x) {
		++ p;
		while(p < N) {
			tree[p] += x;
			p += lowbit(p);
		}
	}

	int query(int p) {
		++ p;
		if(p <= 0) return 0;

		int res = 0;
		while(p) {
			res += tree[p];
			p -= lowbit(p);
		}
		return res;
	}
}bit;


void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) s[i] = (s[i - 1] + a[i]) % m;

	LL ans = 0;
	for (int r = 1; r <= n; r ++) ans += s[r] * r * 1LL;
	for (int l = 1; l <= n; l ++) ans -= s[l - 1] * (n - l + 1) * 1LL;

	LL cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += i - 1 - bit.query(s[i]);
		bit.add(s[i], 1);
	}
	ans += cnt * m * 1LL;						
	cout << ans << endl;
}
```

### 总结
本题难度适中，重在考查对于树状数组的使用，这期间我们要简化我们的公式，这是重中之重。