#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)   
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j < n; j ++)
            if(a[j] % i > a[j + 1] % i)
                swap(a[j], a[j + 1]);
    for (int i = 1; i <= n; i ++)
        printf("%d\n", a[i]);
    return 0;
}