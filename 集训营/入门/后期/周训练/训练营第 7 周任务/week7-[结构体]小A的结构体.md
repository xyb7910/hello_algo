# week7-[结构体]小A的结构体

## 题目描述

有 $n$ 个人，每个人有一个分数，第 $i$ 个人的分数为 $\frac {a_i}{b_i}$，名字为 $s_i$，保证 $a_i,b_i>0$。

请将所有人按照分数大小从小到大的顺序输出名字，如果分数相同，按名字字典序从小到大排序。

对于所有数据，$n\leq 1000$，$0<a_i,b_i\leq 100$，$s_i$ 为长度不超过 $5$ 的小写英文字母字符串。

## 输入格式

输入共 $n+1$ 行。

第 $1$ 行输入 $1$ 个正整数 $n$。

接下来 $n$ 行，第 $i$ 行输入 $2$ 个正整数 $a_i,b_i$ 和字符串 $s_i$。

## 输出格式

输出共 $n$ 行，第 $i$ 行输出排序后顺序为 $i$ 的人的名字。

## 样例 #1

### 样例输入 #1

```
5
1 1 alice
2 1 bob
1 2 carol
1 2 dave
1 1 eve
```

### 样例输出 #1

```
carol
dave
alice
eve
bob
```

## 提示

对于所有数据，$n\leq 1000$，$0<a_i,b_i\leq 100$，$s_i$ 为长度不超过 $5$ 的小写英文字母字符串。