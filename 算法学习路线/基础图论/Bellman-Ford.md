# Bellman-Ford

> 贝尔曼-福特算法（Bellman-Ford）是由理查德·贝尔曼（Richard Bellman） 和 莱斯特·福特 创立的，求解单源最短路径问题的一种算法。有时候这种算法也被称为 Moore-Bellman-Ford 算法，因为 Edward F. Moore 也为这个算法的发展做出了贡献。它的原理是对图进行V-1次松弛操作，得到所有可能的最短路径。其优于迪科斯彻算法的方面是边的权值可以为负数、实现简单，缺点是时间复杂度过高，高达O(VE)。但算法可以进行若干种优化，提高了效率。
## 描述
Bellman-ford算法可以用来处理<font color = "red">存在负权边的单源最短路</font>问题。虽然其算法效率不高，但也解决了Dijkstra算法不能处理负权边的问题。其实现方式是通过m次迭代求出从源点到终点不超过m条边构成的最短路的路径。
## 与Dijkstra的比较
Bellman-ford算法与Dijkstra算法类似，都以<font color = "red"> 松弛操作</font>为基础，即估计的最短路径值渐渐地被更加准确的值替代，直至得到最优解。在两个算法中，计算时每个边之间的估计距离值都比真实值大，并且被新找到路径的最小长度替代。然而,Dijkstra算法以<font color = "red">贪心法</font>选取未被处理的具有最小权值的节点，然后对其的出边进行松弛操作；而Bellman-ford算法简单地对<font color = "red">所有边</font>进行松弛操作，共$\ce{|V|-1}$次，其中$\ce{|V|}$ 是图的点的数量。在重复地计算中，已计算得到正确的距离的边的数量不断增加，直到所有边都计算得到了正确的路径。这样的策略使得Bellman-ford算法比Dijkstra算法适用于更多种类的输入。
## 原理说明
### 松弛
每次松弛操作实际上是对相邻节点的访问，第n次松弛操作保证了所有深度为n的路径最短。由于图的最短路径最长不会经过超过$\ce{|V|-1}$条边，所以可知Bellman-ford算法所得为最短路径。
### 负边权操作
与Dijkstra算法不同的是，Dijkstra算法的基本操作“拓展”是在深度上寻路，而“松弛”操作则是在广度上寻路，这就确定了Bellman-ford算法可以对负边进行操作而不会影响结果。
### 负权环判定
因为负权环可以无限制的降低总花费，所以如果发现第n次操作仍可降低花销，就一定存在负权环。
## 例题
例如，下面的有向图中包含 5 个顶点和 8 条边。假设源点为A。初始化distSet所有距离为∞，源点 A为0。
![](https://files.mdnice.com/user/34286/b2e541b3-1ee9-4bd1-9fca-4e6210f973b8.png)
图中共有五个顶点，按照应该遍历5次，第一次遍历后结果如下：
![](https://files.mdnice.com/user/34286/905e40a3-00fa-4fd4-8c12-252d0cf66ff5.png)
接着执行完所有遍历。
![](https://files.mdnice.com/user/34286/854c635a-e74f-4f68-a1fb-86fa0e5144c9.png)
可以看出最后一行为我们对所有边进行更新后的值。
## 模板
```c++
int n, m;       // n表示点数，m表示边数
int dist[N];        // dist[x]存储1到x的最短路距离

struct Edge     // a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}
```
<font color = "red">&ensp;&ensp;&ensp;&ensp;注意，有时候我们在更新时，可能会忽略数组在更新时的覆盖性，这里建议我们在备份数组上进行操作。</font>


```
















