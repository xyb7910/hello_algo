# week10-[函数]双阶乘

## 题目描述

双阶乘是一个数学概念，用 $n!!$ 表示。

正整数的双阶乘表示不超过这个正整数，且与它有相同奇偶性的所有正整数的乘积。

例如 $6!!=2\times 4\times 6=48$，$5!!=1\times 3\times 5=15$。

给定 $n,p$，求出 $n!!\bmod p$ 的答案。

对于所有数据，$n\leq 10^7$，$2\leq p\leq 10^9$。

你需要在补全以下代码中的函数部分后，提交完整的代码。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n, p;
int calc(int n, int p) {
	___qcodep___ 
}
int main() {
    cin >> n >> p;
    cout << calc(n, p) << endl;
    return 0;
}
```

## 输入格式

输入共 $1$ 行 $2$ 个正整数 $n,p$。

## 输出格式

输出共 $1$ 行 $1$ 个整数，表示答案。

## 样例 #1

### 样例输入 #1

```
6 17
```

### 样例输出 #1

```
14
```

## 提示

对于所有数据，$n\leq 10^7$，$2\leq p\leq 10^9$。