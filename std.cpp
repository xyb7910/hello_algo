#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], f[N][N];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    printf("%d", f[n][n]);
    return 0;
}