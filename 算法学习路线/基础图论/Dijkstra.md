# Dijkstra
>狄克斯特拉算法是从一个顶点到其余各顶点的最短路径算法，解决的是有权图中最短路径问题。迪杰斯特拉算法主要特点是从起始点开始，采用贪心算法的策略，每次遍历到始点距离最近且未访问过的顶点的邻接节点，直到扩展到终点为止。
	
##  问题引入
>> 有一天你成为了公司老总，你的公司在南京，每次你都要去周边的城市去开各种大大小小的会议，从南京出发到达每个城市的花费是不一样的。现在要让你找一条最低费用的路线让身为老总的你去周边开会。（身为老总的你还如此抠搜，哈哈哈）

![](https://files.mdnice.com/user/34286/22868513-1aac-401a-8dc7-5706fa25a007.jpeg)

要实现求距离的话，那么咱们的Dijkstra就要上场了。
## 算法前置知识
首先，咱们要知道Dijkstra算法只能去求解单源最短路问题，就有人问了，什么是单源最短路呢？
> 给定一个带权有向图G=（V,E），其中每条边的权是一个实数。另外，还给定V中的一个顶点，称为源。要计算从源到其他所有各顶点的最短路径长度。这里的长度就是指路上各边权之和。这个问题通常称为单源最短路径问题。

简单的来说就是，只能从<font color = "red">一个顶点出发</font>，求这一个节点到其他点的最短距离而不能任意两点。

其次，使用Dijkstra求解的图中，<font color = "red">不能存在负权边。</font>
## 算法执行流程
对于G={V,E}而言：
1. 初始时令S={V0},T=V-S={其余顶点}，T中顶点对应的距离值。若存在，d(V0,Vi)为弧上的权值；若不存在，d(V0,Vi)为∞ ；
2. 从T中选取一个与S中顶点有关联边且权值最小的顶点W，加入到S中；
3. 对其余T中顶点的距离值进行修改：若加进W作中间顶点，从V0到Vi的距离值缩短，则修改此距离值；

重复上述步骤2、3，直到S中包含所有顶点，即W=Vi为止。

可以看出我们把所有的结点集分为两部分：
*已确定部分* 和 *未确定部分*。

<font color = "#70DB93">举个简单的栗子，清楚理解一下，这里引用一下别人的图</font>
![](https://files.mdnice.com/user/34286/87d5fce3-bd20-49ae-82e3-dc17dc29fec1.jpeg)

![](https://files.mdnice.com/user/34286/7c660fd5-b3dc-4d07-957b-a80c7681bebe.jpeg)


## 算法模板
```c++
int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];   // 存储每个点的最短路是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```
## 使用堆优化

从算法的思想我们可以看出，我们每次从未确定的部分中，选出的永远是最小的值。这个思想就很符合我们之前提到的一个数据结构------堆。


## 算法模板
```c++
typedef pair<int, int> PII;

int n;      // 点的数量
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```