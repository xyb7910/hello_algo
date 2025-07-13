# [2311MT-C] is-a relationship

## 题目描述

在生活中，我们常常会遇到 is-a 关系，即“是一种”关系。例如，教师是一种职业，C++是一种编程语言。我们广泛采用 `A is a kind of B` 的句式来描述 is-a 关系，表示 A 是一种 B。

is-a 关系是一种具有传递性的关系。例如，阳光玫瑰是一种葡萄，葡萄是一种水果，可以推出阳光玫瑰是一种水果。

现在，小 F 使用 `A is a kind of B` 的句式说了 $N$ 句话，每句话可能正确，亦可能错误。**我们假定，当前后的话产生矛盾时，总是引起矛盾的最后一句话是错误的。被认定为错误的话将被直接忽略。** 请你按照输入的顺序输出小 F 说的全部正确的话。

## 输入格式

输入共 $N+1$ 行。

输入的第一行为一个整数 $N$。

接下来 $N$ 行，每行一个形如 `A is a kind of B` 的字符串，表示 A 是一种 B。

保证 A 与 B 不相同，且 A 和 B 中仅包含小写英文字母。

## 输出格式

输出若干行，为 小 F 所说的全部正确的话。

## 样例 #1

### 样例输入 #1

```
6
apple is a kind of fruit
pear is a kind of fruit
apple is a kind of nicefood
nicefood is a kind of fruit
fruit is a kind of pear
pear is a kind of nicefood
```

### 样例输出 #1

```
apple is a kind of fruit
pear is a kind of fruit
apple is a kind of nicefood
nicefood is a kind of fruit
pear is a kind of nicefood
```

## 提示

- 对于 $10\%$ 的测试数据，$N=1$；
- 对于另外 $20\%$ 的测试数据，$N=2$；
- 对于另外 $20\%$ 的测试数据，$|A|=|B|=1$；
- 对于 $100\%$ 的测试数据，$1 \le N \le 1000$，$1 \le |A|,|B| \le 20$，$A,B$ 仅由小写英文字母组成。