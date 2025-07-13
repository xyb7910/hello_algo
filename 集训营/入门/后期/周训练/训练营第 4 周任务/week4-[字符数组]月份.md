# week4-[字符数组]月份

## 题目描述

1月到12月的英语单词分别为：January、February、March、April、May、June、July、August、September、October、November、December。

现在给定其中11个月份的英语单词，请求出没有出现的那个月份对应的英语单词。

## 输入格式

输入11行，每行读入一个字符串，为某个月份对应的英语单词。保证输入的11个字符串互不相同。

## 输出格式

输出1行，该行包括一个字符串，为在输入中没有出现的那个月份对应的英语单词。

## 样例 #1

### 样例输入 #1

```
August
May
June
July
September
January
February
March
November
December
April
```

### 样例输出 #1

```
October
```

## 样例 #2

### 样例输入 #2

```
January
October
July
May
December
August
September
June
April
February
March
```

### 样例输出 #2

```
November
```

## 样例 #3

### 样例输入 #3

```
August
April
February
May
January
October
July
November
December
March
September
```

### 样例输出 #3

```
June
```