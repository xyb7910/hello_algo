# [基础训练营-后期-第十周-T5] Finite Incantatem

## 题目描述

$n+1$ 名观众排队接受庞弗雷夫人的治疗，赫敏排在 $n$ 名观众的最后，观众们自然有一肚子火要吐槽。

赫敏惊奇地发现，前方的第 $i$ 位观众的吐槽能力可以表示为如下的公式（设第 $i$ 位观众的吐槽能力为 $a_i$）：

$$a_i=\dfrac{a_{i-1}+a_{i-2}}{\gcd(a_{i-1},a_{i-2})}\mod p$$

为了耳根清净，赫敏不希望观众们再这样吐槽下去，因此，赫敏决定统计第 $i$ 位观众到第 $j$ 位观众的吐槽能力之和。但是由于某种原因，每发送一次的询问都会消耗一个单位时间。

正当赫敏准备着手这件事时，却惊奇的发现大佬们的吐槽能力正在不断加强：每一个单位时间都会增加 $T$ 个单位的吐槽能力，而发送询问所占用的时间内大佬增加的吐槽能力是需要计算到结果中的。

众所周知，赫敏需要去图书馆，所以她不想自己做这件事，自然就落到你的头上了。

赫敏屈尊降低要求，你只需要告诉她第 $i$ 位观众到第 $j$ 位观众的吐槽能力之和对 $p$ 取模的结果，她热爱数据，所以她要询问 $q$ 次。

## 输入格式

数据共 $q+3$ 行。

第 1 行是两个正整数 $n,T$，表示赫敏前方有 $n$ 个观众和每一位观众的吐槽能力每一个单位时间增值。

第 2 行有三个正整数，表示前两位观众的吐槽能力 $a_1,a_2$ 和$p$。

第 3 行有一个正整数 $q$，表示 $q$ 个询问。

接下来 $q$ 行，每行有2个正整数 $l,r$，表示你需要求出第 $l$ 位观众到第 $r$ 位观众的吐槽能力总和。

## 输出格式

输出共 $q$ 行，每行只有一个正整数，表示区间对应区间内观众的吐槽能力总和。

## 样例 #1

### 样例输入 #1

```
7 0
6 9 998
3
1 4
3 5
2 7
```

### 样例输出 #1

```
34
38
132
```

## 提示

### 输入输出样例说明

吐槽能力初值为 $6,9,5,14,19,33,52$。

### 数据规模与约定

| 测试点编号 |        $n$         |    $T$    |        $q$        |
| :--------: | :----------------: | :-------: | :---------------: |
|    $1$     |      $\le 5$       |   $=0$    |      $=100$       |
|    $2$     |      $\le 10$      | $\le 10$  |      $=200$       |
|    $3$     |      $\le 50$      |   $=0$    |      $=300$       |
|    $4$     |     $\le 100$      | $\le 10$  |      $=400$       |
|    $5$     |     $\le 500$      |   $=0$    |      $=500$       |
|    $6$     |     $\le 10^3$     | $\le 10$  |      $=600$       |
|    $7$     | $\le 2\times 10^3$ |   $=0$    |  $=5\times 10^3$  |
|    $8$     | $\le 5\times 10^3$ | $\le 10$  |      $=10^4$      |
|    $9$     | $\le 8\times 10^3$ |   $=0$    |      $=10^4$      |
|    $10$    |     $\le 10^4$     | $\le 10$  |  $=4\times 10^4$  |
|    $11$    | $\le 2\times 10^4$ |   $=0$    |  $=5\times 10^4$  |
|    $12$    | $\le 5\times 10^4$ | $\le 100$ |  $=5\times 10^4$  |
|    $13$    | $\le 8\times 10^4$ |   $=0$    |  $=5\times 10^4$  |
|    $14$    |     $\le 10^5$     | $\le 200$ |  $=6\times 10^4$  |
|    $15$    |     $\le 10^5$     |   $=0$    |  $=8\times 10^4$  |
|    $16$    | $\le 2\times 10^5$ | $\le 400$ |      $=10^5$      |
|    $17$    | $\le 3\times 10^5$ |   $=0$    |      $=10^5$      |
|    $18$    | $\le 5\times 10^5$ | $\le 400$ |      $=10^5$      |
|    $19$    | $\le 5\times 10^5$ |   $=0$    | $=1.5\times 10^5$ |
|    $20$    | $\le 5\times 10^5$ | $\le 400$ |  $=2\times 10^5$  |
|    $21$    | $\le 5\times 10^5$ |   $=0$    |  $=4\times 10^5$  |
|    $22$    | $\le 5\times 10^5$ | $\le 400$ |  $=4\times 10^5$  |
|    $23$    | $\le 5\times 10^5$ |   $=0$    |  $=5\times 10^5$  |
|    $24$    | $\le 5\times 10^5$ | $\le 500$ |  $=5\times 10^5$  |
|    $25$    | $\le 5\times 10^5$ | $\le 500$ |  $=5\times 10^5$  |

对于 $100\%$ 的数据，$a_1,a_2\le 2\times 10^9$，$p\le 2\times 10^9$。