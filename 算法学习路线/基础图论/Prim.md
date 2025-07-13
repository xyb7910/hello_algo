在将此算法之前我们下来了解一个概念---最小生成树。
>  给定一个图G=(V,E),我们用(u, v)表示一条边，w(u, v)表示边(u, v)的权重，如果存在图T为G的子集，且T里面没有环，如果使得w(T)最小，则T为G的最小生成树Minimum Spanning Tree(MST) 

对于求解最小生成树我们常用的算法就是Prim和Kruskal。

# Prim
Prim是站在点的角度去考虑构建MST，Prim更适用于稠密图。

首先，我们把所有的顶点分为两个部分，**已确定部分**和**未确定部分**。每次向已确定部分中加入的是与未确定部分连接的边的最小值。直到所有顶点全部加入到已确定部分结束位置。

<font color = green>讲个简单的栗子</font>
我们要对一下图求MST。
![](https://files.mdnice.com/user/34286/19c9ec98-29ce-4a10-9467-b293ee5efc62.png)
第一步：将源点加入以确定部分。（这里黑色顶点表示未确定部分，红色顶点表示以确定部分）W = 0。
![](https://files.mdnice.com/user/34286/6ebef8cd-b70c-4dd5-9a14-d7b413d99472.png)
第二步：发现已确定部分和未确定部分有三条边相连（$\ce{V1}$-$\ce{V2}$,$\ce{V1}$-$\ce{V3}$,$\ce{V1}$-$\ce{V4}$），我们发现这三条边中最小的权值位$\ce{V1}$-$\ce{V4}$，所以我们将$\ce{V4}$加入已确定部分。W = 1。

![](https://files.mdnice.com/user/34286/17624bab-6d75-42f4-92b3-fd6810f96d8c.png)
第三步：选出两部分连的边的最小权值边$\ce{V1}$-$\ce{V2}$。我们将$\ce{V2}$加入到已确定部分。W = 3。

![](https://files.mdnice.com/user/34286/ca5e62ba-2f58-4b25-89fe-964472765015.png)
这里我们直接给出最终状态，因为每次我们只能选择一个顶点加入已确定部分。所以我们要执行N次。W = 16。

![](https://files.mdnice.com/user/34286/8bace46c-73c7-4d16-8a7a-79ff14851996.png)

## 算法模板
```c++
// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
```
学过Dijkstra算法的能够看出来，Prim与Dijkstra有异曲同工之妙，所有Prim也可以使用堆来进行优化。由于其原理和Dijkstra差不多，在这里就不给出了。
