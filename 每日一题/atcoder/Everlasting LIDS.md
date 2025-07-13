### Problem Statement

You are given integers $A$, $B$, and $M$.

How many permutations $P = (P_1, \dots, P_{AB-1})$ of $(1, 2, \ldots, AB - 1)$ satisfy all of the following conditions? Find the count modulo $M$.

-   The length of a longest increasing subsequence of $P$ is $A$.
-   The length of a longest decreasing subsequence of $P$ is $B$.
-   There exists an integer $n$ such that appending $n + 0.5$ to the end of $P$ does not change either of the lengths of a longest increasing subsequence and a longest decreasing subsequence.
### 中文题意
#### 问题陈述

给你整数 $A$ 、 $B$ 和 $M$ 。

$(1, 2, \ldots, AB - 1)$ 的 $P = (P_1, \dots, P_{AB-1})$ 排列满足下列所有条件的有多少种？求模数 $M$ 的个数。

- $P$ 的最长递增子序列的长度是 $A$ 。
- $P$ 的最长递减子序列的长度是 $B$ 。
- 存在一个整数 $n$ ，在 $P$ 的末尾添加 $n + 0.5$ 不会改变最长递增子序列和最长递减子序列的长度。
### Constraints

-   All input values are integers.
-   $2 \leq A, B$
-   $AB \leq 120$
-   $10^8 \leq M \leq 10^9$
-   $M$ is a prime.
### Input

The input is given from Standard Input in the following format:


$A$ $B$ $M$
### Output

Print the number of permutations satisfying the conditions, modulo $M$.
### Sample Input 1

```
3 2 998244353
```
### Sample Output 1

```
10
```

For example, $P = (2, 4, 5, 1, 3)$ satisfies the conditions. This can be confirmed as follows:

-   The length of a longest increasing subsequence of $P$ is $3$.
-   The length of a longest decreasing subsequence of $P$ is $2$.
-   For $n = 4$, the lengths of longest increasing and decreasing subsequences of $(2, 4, 5, 1, 3, 4.5)$ are $3$ and $2$, respectively.

There are $10$ permutations of $(1, 2, 3, 4, 5)$ that satisfy the conditions.
### Sample Input 2

```
10 12 924844033
```
### Sample Output 2

```
623378361
```

Print the count modulo $M$.

### 解法
