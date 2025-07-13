## BFS

### 描述
BFS称为宽度优先搜索或者广度优先搜索。宽度优先搜索以一种系统的方式探寻图`G`的边，从而“发现”边`s`所能到达的所有顶点，并计算边`s`到所有这些顶点的距离(最少边数)，该算法同时能生成一棵根为`s`且包括所有可达顶点的**宽度优先树**。

对从`s`可达的任意顶点v，宽度优先树中从`s`到`v`的路径对应于图`G`中从`s`到`v`的最短路径，即包含**最小边数的路径**。

之所以称之为宽度优先算法，是因为算法自始至终一直通过已找到和未找到顶点之间的边界向外扩展，就是说，算法首先搜索和`s`距离为`k`的所有顶点，然后再去搜索和`S`距离为`k+l`的其他顶点。

对于BFS来说，每次扩展的节点为当前节点的所有节点，其中我们可以通过**队列**来辅助实现。

<font color = green>图中的数字表示第几次遍历到的节点。</font>
![](https://files.mdnice.com/user/34286/e2e31073-ca2e-44ed-b0c9-ffef1534acf5.png)
### 应用
求图论或者树中解最短路径或者最短步数。

## 例题
**1.走迷宫**

给定一个 `n×m` 的二维整数数组，用来表示一个迷宫，数组中只包含 `0` 或 `1`，其中 `0` 表示可以走的路，`1` 表示不可通过的墙壁。

最初，有一个人位于左上角 ``(1,1)`` 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 `(n,m)` 处，至少需要移动多少次。

数据保证 `(1,1)` 处和 `(n,m)` 处的数字为 `0`，且一定至少存在一条通路。

分析
题目让我们求至少要移动多少次？我们可以直接转换为**求从左上角到右下角通过`1`最短路问题**。

使用下列情况模拟一下BFS，图中的数字表示扩充的顺序。

![](https://files.mdnice.com/user/34286/4773711d-4f8c-49e2-9d5c-b4a7076e6423.png)



```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int dist[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//定义偏移量数组，分别表示向上，向左，向下，向右
typedef pair<int, int> PII;

int bfs()
{
    queue<PII> q;
    
    memset(dist, -1, sizeof dist);//将距离初始化为-1
    dist[0][0] = 0;//对起点进行初始化
    
    q.push({0, 0});//先将第一个点加入队列，否则BFS无法开始
    
    while(q.size())//当队列不为空的时候，我们可以已知遍历
    {
        auto t = q.front(); //取出队头元素
        q.pop();
        
        for (int i = 0; i < 4; i ++ ) //对节点进行扩充
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            
            if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0 && dist[a][b] == -1) //扩充节点必须满足条件
            {
                dist[a][b] = dist[t.first][t.second] + 1; //更行距离数组
                q.push({a, b});//将扩充节点加入到队列之中
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        cin >> g[i][j];
    
    cout << bfs() << endl;
    return 0;
}
```
