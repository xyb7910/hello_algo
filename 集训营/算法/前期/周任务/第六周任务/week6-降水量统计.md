# week6-降水量统计

## 题目描述

Z 城市今年由于突如其来的暴雨，遭受到了严重的洪涝灾害。为了进行事后总结，他们正在进行数据分析。其中有一项数据是 $t$ 分钟的滑动降水量，指的是**连续** $t$ 分钟的降水量总和。

作为气象台人士，你有权限获得每一分钟的降水量，共 $n$ 个数据且已经按照时间顺序整理好了。你需要做的是，计算出 $t$ 分钟的滑动降水量的**最大值**，以及其是从哪一分钟开始，哪一分钟结束。始末时间只需求出**最早**的那一组。

## 输入格式

第一行，输入两个整数 $n,t$，以空格隔开。

第二行，输入 $n$ 个浮点数 $a_i$，表示每一分钟的降水量。保证最多出现一位小数。

## 输出格式

共一行，三个整数，分别表示 $t$ 分钟滑动降水量最大值（保留一位小数）以及其始末时间。

三个数字之间以空格隔开。

## 样例 #1

### 样例输入 #1

```
5 3
1 2 3 4 5
```

### 样例输出 #1

```
12.0 3 5
```

## 样例 #2

### 样例输入 #2

```
10 3
1.1 2.3 1.1 7.1 6.9 5.8 1.5 1.3 1.2 1.0
```

### 样例输出 #2

```
19.8 4 6
```

## 提示

对于所有数据，$1 \leq n \leq 10000,1 \leq t \leq 1440$，且 $t \leq n$；$0 \leq a_i \leq 20$。

对于前 $60\%$ 的数据，降水量数据保证不出现任何浮点数。

对于前 $80\%$ 的数据，$1 \leq n \leq 100,1 \leq t \leq 40$。