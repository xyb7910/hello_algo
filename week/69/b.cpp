#include <bits/stdc++.h>
using namespace std;
const int N = 110;
bool st[N][N];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x, y; cin >> x >> y;
        for (int j = x; j < x + 10; j ++)
            for (int k = y; k < y + 10; k ++)
                st[j][k] = 1;
    }
    int cnt = 0;
    for (int i = 0; i <= 100; i ++)
        for (int j = 0; j <= 100; j ++)
            if(st[i][j]) cnt ++;
    cout << cnt;
    return 0;
}