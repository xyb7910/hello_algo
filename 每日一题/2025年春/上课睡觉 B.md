题目链接：https://www.luogu.com.cn/problem/P8183

题目解析：

假设最小的操作次数为 $x$。

每次合并的话，石头的堆数就会减少 $1$ 堆。那么最终的石头堆数就为 $n - x$。

那么每一对石子就会有 $$y = \frac{ \sum_{i=0}^{n} a_i}{n - x}   $$ 个石头。（那么$n - x$ 是 $sum$ 的因子，$y$ 也是 $sum$ 的因子。）

可以看出来，$y$ 与 $x$ 乘正比例。

对于每一个整数，因子个数是有限的。

因此，我们可以枚举每一个 $y$，然后检查每一个 $y$ 是否可以作为最终每一堆石子的数量，如果可以就找到了最小的 $y$, 也找到了最小的 $x$。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int w[N];

bool check(int cnt)
{
    for (int i = 0, s = 0; i < n; i ++ )
    {
        s += w[i];
        if (s > cnt) return false;
        if (s == cnt) s = 0;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i ++ )
        {
            scanf("%d", &w[i]);
            sum += w[i];
        }

        for (int i = n; i; i -- )
            if (sum % i == 0 && check(sum / i))
            {
                printf("%d\n", n - i);
                break;
            }
    }
    return 0;
}
	```