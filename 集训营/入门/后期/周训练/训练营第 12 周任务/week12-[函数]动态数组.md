# week12-[函数]动态数组

## 题目描述

对于某些需要使用二维数组的问题，但是只知道整个数组的大小，而每一维的大小是不确定的，如果直接使用二维数组可能会造成空间的浪费，这时候我们可以使用一维数组来代替二维数组的功能。

你需要完成 $k$ 个任务，对于每个任务，会给定四个非负整数 $n,m,i,j$

你现在有一个大小为 $n\times m$ 的二维数组 $a_{i,j}$，以及一个大小为 $n\times m$ 的一维数组 $b_{t}$

如果令数组 $a$ 按 $a_{1,1},a_{1,2},\cdots,a_{1,m},a_{2,1},a_{2,2},\cdots,a_{n,1},\cdots,a_{n,m}$ 的顺序，数组 $b$ 按 $b_{1},b_{2},\cdots,b_{n\times m}$ 的顺序一一对应，你需要计算出一个非负整数 $t$，满足：$a_{i,j}$ 正好对应 $b_{t}$

你需要补全下面代码中的函数部分后提交完整代码。

```
#include<bits/stdc++.h>
using namespace std;

int get_ans(int n,int m,int i,int j){
	>在此补全代码<
}

int main(){
	int k;
	cin>>k;
	while(k--){
		int n,m;
		cin>>n>>m>>i>>j;
		cout<<get_ans(n,m,i,j)<<endl;
	}
	return 0;
}
```

## 输入格式

第一行一个正整数 $k$

接下来 $k$ 行，每行两个整数 $n,m,i,j$，表示一个任务。

## 输出格式

输出 $k$ 行，每行表示对应的任务的结果。

## 样例 #1

### 样例输入 #1

```
2
5 3 5 1
4 4 4 1
```

### 样例输出 #1

```
13
13
```

## 提示

$1\leq k\leq 10,1\leq m\leq n\leq 100$