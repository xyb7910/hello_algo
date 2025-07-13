# Flood Fill

## 算法描述
Flood fill算法是计算机图形学和计算机游戏开发中常用的一种算法，用于填充区域和寻找连通区域。其主要思想是从指定的起始点开始，沿着该点的相邻像素（或者单元格）进行遍历，将所有与起始点相连通的点（或者单元格）都涂上同一种颜色或标记。这个过程就像是把墨水泼在一块海绵上，不断扩散，直到整个海绵都变成了同一种颜色。

## 具体流程
- 首先需要给定一个起始点（x, y）和要填充的颜色c。
- 将起始点(x, y)入队。
- 当队列非空时，从队列头取出一个元素(x, y)，然后将其标记为颜色c。
- 遍历当前元素(x, y)的四联通相邻点（即上下左右四个方向），如果相邻点没有被标记过且与当前点的颜色相同，就将其加入队列中。
- 重复步骤3和步骤4，直到队列为空。

## 实例

实现了一个二维数组的Flood Fill算法，该算法从给定的起始点(sr, sc)开始，遍历整个相邻区域，并将其颜色标记为newColor。在实现中，使用了一个二维的 vector<int> 数组来表示图像，其值为0或1，表示黑色或白色。在示例中，我们将 (1,1) 这个白色像素标记为红色(2)，然后输出整个图像。

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size(), n = image[0].size();
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        image[x][y] = newColor;
        if (x > 0 && image[x - 1][y] == oldColor) q.push({x - 1, y});
        if (x < m - 1 && image[x + 1][y] == oldColor) q.push({x + 1, y});
        if (y > 0 && image[x][y - 1] == oldColor) q.push({x, y - 1});
        if (y < n - 1 && image[x][y + 1] == oldColor) q.push({x, y + 1});
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    floodFill(image, sr, sc, newColor);
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}
```
实现将起始点(x, y)存储在一个 pair<int, int> 类型的队列中，每次从队列中取出一个元素并将其周围的相邻点加入队列中，直到队列为空。其中，pair<int, int> 表示点的坐标。注意，在实现中需要特别处理起始点颜色和新颜色相同的情况，否则算法可能会陷入死循环。

上边只是给大家做个引入，让大家了解一下算法的思想，毕竟了解算法还是为了更好的运用么，接下来我们进入正戏。

## 训练题

 ### 1.池塘计数

**Tag：朴素版**
  
每个单元格内，如果包含雨水，则用”W”表示，如果不含雨水，则用”.”表示。

现在，约翰想知道他的土地中形成了多少片池塘。

每组相连的积水单元格集合可以看作是一片池塘。

每个单元格视为与其上、下、左、右、左上、右上、左下、右下八个邻近单元格相连。

请你输出共有多少片池塘，即矩阵中共有多少片相连的”W”块。

**输入格式**
  
第一行包含两个整数 N
 和 M
。

接下来 N
 行，每行包含 M
 个字符，字符为”W”或”.”，用以表示矩形土地的积水状况，字符之间没有空格。

**输出格式**
  
输出一个整数，表示池塘数目。

**数据范围**
  
$1≤N,M≤1000$
  
**输入样例**
```
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
```
**输出样例**
```
3
```
  
代码展示
  
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = N * N;
int n, m;
char g[N][N];
int cnt;
bool st[N][N];
PII q[M];

void bfs(int tx, int ty)
{
  //这里我使用手写队列
    int hh = 0, tt = 0;
    
    q[0] = {tx, ty};
    st[tx][ty] = true;
    
    while(hh <= tt) //队列非空
    {
        PII t = q[hh ++];
        
        for (int i = t.x - 1; i <= t.x + 1; i ++)
            for (int j = t.y - 1; j <= t.y + 1; j ++)
            {
                if(i == t.x && j == t.y) continue; //跳过自己本身
                if(i < 0 || i >= n || j < 0 || j >= m) continue;//防止位置越界
                if(g[i][j] == '.' || st[i][j]) continue;//不满足此题条件
                
                q[++ tt] = {i, j};
                st[i][j] = true;
            }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i ++) scanf("%s", g[i]);
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if(g[i][j] == 'W' && !st[i][j])
            {
                bfs(i, j);
                cnt ++;
            }
            
    printf("%d\n", cnt);
    return 0;
}
```
## 2.城堡问题
**Tag：二进制 + Flood Fill**
  ```c++
    1   2   3   4   5   6   7  
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           (图 1)

   #  = Wall   
   |  = No wall
   -  = No wall

   方向：上北下南左西右东。
```
图1是一个城堡的地形图。

请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。

城堡被分割成 m∗n
个方格区域，每个方格区域可以有0~4面墙。

注意：墙体厚度忽略不计。

输入格式
第一行包含两个整数 m
 和 n
，分别表示城堡南北方向的长度和东西方向的长度。

接下来 m
 行，每行包含 n
 个整数，每个整数都表示平面图对应位置的方块的墙的特征。

每个方块中墙的特征由数字 P
 来描述，我们用1表示西墙，2表示北墙，4表示东墙，8表示南墙，P
 为该方块包含墙的数字之和。

例如，如果一个方块的 P
 为3，则 3 = 1 + 2，该方块包含西墙和北墙。

城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。

输入的数据保证城堡至少有两个房间。

**输出格式**
                              
共两行，第一行输出房间总数，第二行输出最大房间的面积（方块数）。

**数据范围**
                              
$1≤m,n≤50,
0≤P≤15$
                              
**输入样例**
```
4 7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13 
```
**输出样例**
```
5
9
```
代码展示
							  
```c++
//这个题我们要能将一个题目所给的条件转化为二进制的判断，这个是难点！！
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 60,  M = N * N;
int n, m;
int g[N][N];
bool st[N][N];
PII q[M];

int bfs(int sx, int sy)
{
    int tt = 0, hh = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    
    int area = 0;
    while(hh <= tt)
    {
        PII t = q[hh ++];
        area ++;
        
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            
            if(st[x][y]) continue; //表示次位置之前已经遍历过
            if(x < 0 || x >= n || y < 0 || y >= m) continue; //出界
            if(g[t.x][t.y] >> i & 1) continue; //表示此位置是障碍物
         
            
            q[++ tt] = {x, y};
            st[x][y] = true;
        }
    }
    return area;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            scanf("%d", &g[i][j]);
    
    int area = -1, cnt = 0;
    for (int i = 0; i < n; i ++ )  
        for (int j = 0; j < m; j ++ )
            if(!st[i][j])
            {
                area = max(area, bfs(i, j));
                cnt ++;
            }
            
    printf("%d\n%d\n", cnt, area);
    return 0;
}
```

## 3.山峰和山谷  
FGD小朋友特别喜欢爬山，在爬山的时候他就在研究山峰和山谷。

为了能够对旅程有一个安排，他想知道山峰和山谷的数量。

给定一个地图，为FGD想要旅行的区域，地图被分为 n×n
 的网格，每个格子 (i,j)
 的高度 w(i,j)
 是给定的。

若两个格子有公共顶点，那么它们就是相邻的格子，如与 (i,j)
 相邻的格子有(i−1,j−1),(i−1,j),(i−1,j+1),(i,j−1),(i,j+1),(i+1,j−1),(i+1,j),(i+1,j+1)
。

我们定义一个格子的集合 S
 为山峰（山谷）当且仅当：

S
 的所有格子都有相同的高度。
S
 的所有格子都连通。
对于 s
 属于 S
，与 s
 相邻的 s′
 不属于 S
，都有 $w_s>w_s′$（山峰），或者 $ w_s<w_s′ $（山谷）。
                  
如果周围不存在相邻区域，则同时将其视为山峰和山谷。
                  
你的任务是，对于给定的地图，求出山峰和山谷的数量，如果所有格子都有相同的高度，那么整个地图即是山峰，又是山谷。

**输入格式**
                   
第一行包含一个正整数 n，表示地图的大小。

接下来一个 n×n的矩阵，表示地图上每个格子的高度 w
。

**输出格式**
                  
共一行，包含两个整数，表示山峰和山谷的数量。

**数据范围**
                  
$1≤n≤1000,0≤w≤10^9$
**输入样例1**
```
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8
```
**输出样例1**
```
2 1
```
**输入样例2**
```
5
5 7 8 3 1
5 5 7 6 6
6 6 6 2 8
5 7 2 5 8
7 1 0 1 7
```
**输出样例2**
```
3 3
```
**样例解释**
                  
样例1


![](https://files.mdnice.com/user/34286/225c71d4-a083-4ed0-b4d4-b8191e61777b.png)

样例2：


![](https://files.mdnice.com/user/34286/22f1e7d8-f499-4ed3-8e2c-1e5b79c4759b.png)
代码展示：
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;
int n;
int g[N][N];
bool st[N][N];
PII q[M];

void bfs(int sx, int sy, bool& is_higher, bool& is_lower)
{
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    
    while(hh <= tt)
    {
        PII t = q[hh ++];
        
        for (int i = t.x - 1; i <= t.x + 1; i ++ )
            for (int j = t.y - 1; j <= t.y + 1; j ++ )
            {
                //一定要注意continue条件的判断
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                
                if(g[i][j] != g[t.x][t.y]) //山峰的边界
                {
                    if(g[i][j] > g[t.x][t.y]) is_higher = true;//说明此时仍存在更高的位置
                    else if(g[i][j] < g[t.x][t.y]) is_lower = true;//说明此时仍存在更低的位置
                }
                else if(!st[i][j])
                {
                    q[++ tt] = {i, j};
                    st[i][j] = true;
                }
            }
    }
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            scanf("%d", &g[i][j]);
            
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if(!st[i][j])
            {
                bool is_higher = false, is_lower = false;
                bfs(i, j, is_higher, is_lower);
                if(!is_higher) peak ++;
                if(!is_lower) valley ++;
            }
    printf("%d %d\n", peak, valley);
    return 0;
}

```

## 总结
                              
你可能会发现Flood Fill算法本质上还是基于BFS实现的，使用队列作为数据载体。

我们在使用Flood Fill算法去解题的时候一定要注意下一步条件的判断。
                              
就如，最难的第三题，我们不仅要判断普遍条件（位置越界）还要考虑基于本道题目的特殊条件（山峰的边界判断）。
                              
总之，我们在解题时一定要多花时间去考虑边界问题！！！


