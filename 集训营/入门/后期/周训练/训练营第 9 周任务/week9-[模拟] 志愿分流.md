# week9-[模拟] 志愿分流

## 题目描述

大类招生的高校一般会在入学一段时间后按照课业成绩进行专业分流，把学生划分到若干个专业中。  
Z 所在的学院现在要分流了，一共有 $m$ 个专业，分别用整数 $1\sim m$ 表示，这 $m$ 个专业分别最多录取 $x_1,x_2\cdots x_m$ 位同学，一共有 $n$ 名同学，每位同学可以填写第一志愿专业和第二志愿专业。  
分流录取时，先把所有同学按照课业成绩从高到低排序，再从前往后依次考虑每个同学，如果当前同学的第一志愿专业还能继续录取，那么该同学会被录取到该专业中，否则考虑该同学的第二志愿专业，如果可以将该同学录取到第二志愿专业就将其录取到第二志愿专业中，如果均无法录取则将其录取到剩余的专业中可录取的编号最小的专业（保证每个同学都能被录取到某个专业中）。  
现在告诉你 $n$ 名同学的志愿填报情况以及他们的课业成绩，请你按照上述规则进行分流录取，输出最后每位同学的录取专业。

## 输入格式

第一行四个以空格隔开的整数 $n,m$，含义如题目所述。  
接下来一行 $m$ 个以空格隔开的整数 $x_1,x_2\cdots x_m$ 分别表示第 $1\sim m$ 个专业的录取上限人数。  
接下来 $n$ 行，每行两个以空格隔开的整数 $x,y$，依次表示该同学的第一、第二志愿专业。  
接下来一行有 $n$ 个以空格隔开的浮点数 $a_1,a_2\cdots a_n$，依次表示第 $1\sim n$ 位同学的课业成绩，保证小数位不超过 $3$ 位，保证没有任何两名同学课业成绩相同。

## 输出格式

一行 $n$ 个以空格隔开的整数，依次表示第 $1\sim n$ 位同学最后录取的专业。

## 样例 #1

### 样例输入 #1

```
5 3
1 2 2 
2 3
1 1
1 1
1 3
2 2
1.25 8.77 0.9 9.99 9.53
```

### 样例输出 #1

```
3 2 3 1 2
```

## 提示

对于全部测试数据满足：  
$1\le n\le 1000$，$1\le m,x_i\le10^3$，$x_1+x_2+\cdots +x_m\geq n$，$x,y\in[1,m]$，$0<a_i<100$。