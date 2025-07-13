# Tire树和并查集

## Tire 树的概念

Trie 树，即字典树，又称单词查找树或键树，是一种树形结构，是一种哈希树的变种。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。

它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。

Trie 的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

3 个基本性质：

1. 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
3. 每个节点的所有子节点包含的字符都不相同。

<font color = " #70DB93">举个栗子来更透彻的了解 Tire 到底是什么东西？</font><br>
将`abcdef`,`abdef`,`aced`,`bcdf`,`bcff`,`cdaa`,`abc`，这七个单词插入Tire树的时候，得到如下Tire树。
![](https://files.mdnice.com/user/34286/40c9ea64-1329-4720-8121-5ec0e2d8ea2a.jpg)

基本操作：
插入，查询，删除，其中删除操作不常用。
## Tire树模板
```c++
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
```
## 例题
Acwing835. Trie字符串统计
维护一个字符串集合，支持两种操作：

1. `I` `x` 向集合中插入一个字符串 `x`；
2. `Q` `x` 询问一个字符串在集合中出现了多少次。

共有 `N` 个操作，输入的字符串总长度不超过 ${1 0^5 }$ ，字符串仅包含小写英文字母。
```c++
#include <iostream>
using namespace std;
const int N = 20010;
int p[N][26], cnt[N], idx;
char str[N];

void insert(char *str)
{
    int f = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!p[f][u]) p[f][u] = ++ idx;
        f = p[f][u];
    }
    cnt[f] ++;
}
int query(char *str)
{
    int f = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!p[f][u]) return 0;
        f = p[f][u];
    }
    return cnt[f];
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}
```