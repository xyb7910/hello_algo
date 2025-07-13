相对于Prim来说，[[Kruskal]]是站在边的角度去考虑如何构建MST的。它的具体步骤如下：
1. 将边按照权重从小到大排列
2. 枚举第一个边，加入MST里，判断是否成环
3. 如果成环则跳过，否则确定这条边为MST里的
4. 继续枚举下一条边，直到所有的边都枚举完

同样咱们上边的图去构建MST。
第一步：将第一个最小的边加入。
![](https://files.mdnice.com/user/34286/b373d4ed-b509-4a9d-b369-bbb090a5ed0e.png)
第二步：第二个最小（因为有两个最小的边，我们先加哪一个都是可以的）

![](https://files.mdnice.com/user/34286/f29d4b53-9ec9-43da-8010-8b625add0912.png)
 第三步与第四步同理。
![](https://files.mdnice.com/user/34286/87e6d7ae-a335-4a85-9a44-15ddfdb180ea.png)

第五步：$\ce{V2}$-$\ce{V4}$为最小边权此时为3，因为构成了环，所以我们要舍弃。同样的道理我们可以跳过$\ce{V1}$-$\ce{V3}$,但是我们可以把$\ce{V4}$-$\ce{V7}$加入并且不构成环。
![](https://files.mdnice.com/user/34286/0356b4b6-b6de-4f68-9514-695415756d8b.png)
省略一些步数，我们直接给出最终图。
![](https://files.mdnice.com/user/34286/ca745ad7-ad41-4304-8707-f3aa85956695.png)

此时，我们使用此算法求解MST结束。

可以看出对于Kruskal算法来说我们要循环的次数和边数成正比，所以Kruskal算法更适合于稀疏图。

看懂了Kruskal算法的实现思路，我们来想一下这和我们之前见到过的一个数据结构很像，没错，那就是并查集了，我们可一借助并查集来辅助实现此算法，并且优化了效率。
## 算法模板
```c++
struct Edge     // 存储边
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)     // 并查集核心操作
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)     // 如果两个连通块不连通，则将这两个连通块合并
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}
```

