# week8-[函数] 斜率

## 题目描述

求斜率是一个很重要的事情。

> 斜率是用来刻画直线倾斜程度的量， 一般地， 对于两个点 $(x_1, y_1), (x_2, y_2)$ ，斜率 $k$ 的计算方式是 $k = \frac{y_1 - y_2}{x_1 - x_2}$ 。

下面给出两个数组 $x, y$ 表示点的二维坐标， 请求出两两点间斜率的最大值。

你需要在补全以下代码后，提交完整的代码。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;

int n;
double x[N], y[N];

double get(int i, int j) {
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
	double ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			ans = max (ans, get(i, j));
	cout << ans << endl;
	return 0;
}
```

## 输入格式

第一行一个整数 $n$ 表示点的个数。

接下来 $n$ 行每行两个数表示点的 $x, y$ 坐标。

## 输出格式

一行一个实数表示答案。 与标准答案误差在 $10^{-5}$ 以内即可。

## 样例 #1

### 样例输入 #1

```
8
6 7
8 6
3 6
5 3
4 8
1 3
7 7
2 5
```

### 样例输出 #1

```
4
```

## 提示

$2 \leq n \leq 3000$

保证所有数在 int 以内。