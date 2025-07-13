# SPFA
> SPFA 算法是 [[Bellman-Ford]]算法的队列优化算法的别称，通常用于求含负权边的单源最短路径，以及判负权环。SPFA 最坏情况下时间复杂度和朴素Bellman-Ford 相同为O(VE)。

## 描述
设立一个先进先出的队列用来保存待优化的结点，优化时每次取出队首结点u，并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。这样不断从队列中取出结点来进行松弛操作，直至队列空为止。
## 例题
![](https://files.mdnice.com/user/34286/90334327-fa85-42af-887a-a64b1e85e698.png)
过程：
![](https://files.mdnice.com/user/34286/e0a4248c-becb-4768-8a44-f2925f4170ba.png)
此时将顶点a入队，当队列非空的时候，将队头弹出队列，然后对以a为起点的所有边的终点（b, c, d）进行”松弛“操作。
![](https://files.mdnice.com/user/34286/8f7b5ad7-3352-458c-84ce-70532975e00c.png)
我们对（b, c, d）这三个点的最短路径进行了调整，因为此前这三个元素没有在队列中所以我们要将他们入队。<br>
此时队列中是以b为队头，我们将队头b出队，然后对其他点（e）进行”松弛“操作。
![](https://files.mdnice.com/user/34286/dc5f6f6d-2bf1-4e1c-8404-e4589a9b3f18.png)
我们对e的最短距离进行更新，因为e此前没有在队列中出现过，所以把e加入队列，此时队头元素为c，我们接着执行同样的操作。
![](https://files.mdnice.com/user/34286/6b00c7f6-55e3-4b3d-bbc9-6773c2050aa3.png)
此时我们对e点和f点的最短距离进行了更新。因为此前e点在队列中，f点不在队列中，所以我们将f点加入到队列中。<br>
接着我们将队头元素d出队，对g点进行更新。
![](https://files.mdnice.com/user/34286/5f07a7df-5e13-4ad2-a96c-c9b9e6b4e7ee.png)
将对头元素e出队，e点出队对最短距离没有进行更新。<br>
将队头元素f出队，对其所连的顶点（d,e,f）进行更新。
![](https://files.mdnice.com/user/34286/8da110d7-bd97-48f8-8d5c-a23024f76cbe.png)
可知，我们对e点和g点进行了更新。因为此时队列中没有e点所以我们将e点入队。<br>
将队头元素g出队，更新b点。
![](https://files.mdnice.com/user/34286/323bca47-064e-4bbf-9b2a-fded0c478ecf.png)
因为b不在队列中所以我们将b入队。<br>
将队头元素e出队，发现无法更新最短距离。<br>
将队头元素b出队，发现也无法更新最短距离。<br>
<font color = "red">此时结束。</font>
## 算法模板
```c++
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```
## spfa的应用---判断是否存在负环
```c++
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N], cnt[N];        // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];     // 存储每个点是否在队列中

// 如果存在负环，则返回true，否则返回false。
bool spfa()
{
    // 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。

    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;       // 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}