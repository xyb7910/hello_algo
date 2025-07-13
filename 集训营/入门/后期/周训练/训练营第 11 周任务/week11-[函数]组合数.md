# week11-[函数]组合数

## 题目描述

总所周知组合数 $\tbinom{n}{m}$ 表示从 $n$ 个不同物品中取出 $m$ 个的方案数，其计算方式是 $\tbinom{n}{m}=\frac{n!}{m!(n-m)!}$，其中 $n!$ 表示阶乘。

你需要完成 $k$ 个计算任务，每个计算任务包含两个数 $n,m$，你需要求出 $\tbinom{n}{m}$

你需要补全下面代码中的函数部分后提交完整代码。

```
#include<bits/stdc++.h>
using namespace std;

int fac(int n){
	>在此补全代码<
}

int main(){
	int k;
	cin>>k;
	while(k--){
		int n,m;
		cin>>n>>m;
		cout<<fac(n)/fac(m)/fac(n-m)<<endl;
	}
	return 0;
}
```

## 输入格式

第一行一个正整数 $k$

接下来 $k$ 行，每行两个整数 $n,m$，表示一个计算任务。

## 输出格式

输出 $k$ 行，每行表示对应的计算任务的结果。

## 样例 #1

### 样例输入 #1

```
2
2 0
5 4
```

### 样例输出 #1

```
1
5
```

## 提示

$1\leq k\leq 10,0\leq m\leq n\leq 12$