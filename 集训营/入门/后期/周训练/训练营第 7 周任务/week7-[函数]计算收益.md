# week7-[函数]计算收益

## 题目描述

想象一下，你有一个小店，里面放了 $n$ 种不同的物品。每种物品都有自己的数量和进货价格。例如，第 $i$ 种物品你有 $a_i$ 个，每个进货价格是 $b_i$ 元。

现在，有人来问你一个很有趣的问题：如果我想要以某个价格 $k$ 来卖出这些物品，那么我能赚多少钱呢？注意哦，这里说的“赚的钱”可能是负的，也就是说，如果卖出价格比进货价格还低，那你可能还要亏钱呢！

现在，我们有 $m$ 次这样的询问，每组都给出了一个售价 $k$。你的任务是，对于每一组询问，都计算出如果以 $k$ 的价格卖出所有物品，你能赚多少钱。

为了简化问题，我们假设每种物品的数量和进货价格都不会超过 100，询问的次数也不会超过 100。

那么，你能帮助这个小店老板计算出每一组询问的答案吗？

你需要在补全以下代码中的函数部分后，提交完整的代码。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, k, a[N], b[N];
int calc(int x) {
	___qcodep___//请删除此行后补充完整的代码
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    while (m--) {
        cin >> k;
        cout << calc(k) << endl;
    }
    return 0;
}
```

## 输入格式

输入共 $n+m+1$ 行。

第 $1$ 行输入 $2$ 个正整数 $n,m$。

接下来 $n$ 行，第 $i$ 行输入 $2$ 个正整数 $a_i,b_i$。

接下来 $m$ 行，每一行输入 $1$ 个正整数 $k$，表示一次询问。

## 输出格式

输出共 $m$ 行，每行输出一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
3 3
1 10
2 5
1 10
10
5
8
```

### 样例输出 #1

```
10
-10
2
```

## 提示

对于所有数据，$n,m,k,a_i\leq 100$。