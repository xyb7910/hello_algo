# 一、 扫地机器人
**题目链接**：https://www.luogu.com.cn/problem/U422199

**代码**:

解法一：

```cpp
#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int n, m;
int map[N][N];

/*
dfs函数的功能：在第 (x, y) 的位置上填上 k
*/

void dfs(int x, int y, int k) {
    // 判断边界，提前剪枝
    if(x < 1 || x > n || y < 1 || y > m || map[x][y]) return ;
    map[x][y] = k;
    // 右边
    dfs(x, y + 1, k + 1);
    // 下边
    dfs(x + 1, y, k + 1);
    // 左边
    dfs(x, y - 1, k + 1);
    // 上边
    dfs(x - 1, y, k + 1);
}

int main() {
    cin >> n >> m;
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

解法二：

```cpp
#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int map[N][N];
/*
dfs函数的功能：在第 (x, y) 的位置上填上 k
*/
void dfs(int x, int y, int k) {
    // 判断边界，提前剪枝
    if(x < 1 || x > n || y < 1 || y > m || map[x][y]) return ;
    map[x][y] = k;
    for (int i = 0; i < 4; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        dfs(tx, ty, k + 1);
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

# 二、 迷宫寻路

**题目链接**： https://www.luogu.com.cn/problem/B3625

**代码**：

解法一：
```cpp
#include <iostream>

using namespace std;
const int N = 110;
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char map[N][N];
bool st[N][N];
/*
dfs 函数的功能：判断地图位置 (x, y) 是否可以走
*/
bool dfs(int x, int y) {
    if(x == n && y == m) return true;
    st[x][y] = true;
    for (int i = 0; i < 4; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m 
        	&& map[tx][ty] == '.' && !st[tx][ty]) {
        	if(dfs(tx, ty)) return true;
        } 
    }
    return false;
}
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) 
            cin >> map[i][j];

    printf("%s", dfs(1, 1) ? "Yes" : "No");
    return 0;
}
```

解法二：

```cpp
#include <iostream>
using namespace std;

const int N = 1e2 + 10;
int n, m;
bool st[N][N], is_target;
char map[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if (x == n && y == m) {
        is_target = true;
        return;
    }

    st[x][y] = true;

    for (int i = 0; i < 4; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
            && map[tx][ty] == '.' && !st[tx][ty]) {
            dfs(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> map[i][j];  

    dfs(1, 1);

    cout << (is_target ? "Yes" : "No") << endl;
    return 0;
}
```
# 三、 池塘计数
题目链接： https://www.luogu.com.cn/problem/P1596

代码：

```cpp
#include <iostream>
using namespace std;

const int N = 110;
int n, m, cnt;
char map[N][N];

void dfs(int x, int y) {
    map[x][y] = '.';  // 将当前有水区域抽干
    
    int dx[8]={1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8]={1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        // 检查边界条件
        if (map[tx][ty] == 'W') {
            dfs(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++)
            cin >> map[i][j];
            
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (map[i][j] == 'W') {
                dfs(i, j);
                cnt ++;
            }
    
    cout << cnt;
    return 0;
}
```
