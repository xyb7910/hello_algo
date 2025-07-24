#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
const double INF = 1e18;
PII p[N], tmp[N];
double dist(PII a, PII b) {
    LL dx = a.first - b.first;
    LL dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

double dfs(int l, int r) {
    if (l >= r) return INF;     
    if (l + 1 == r) return dist(p[l], p[r]); 
    int mid = l + r >> 1;
    double d = min(dfs(l, mid), dfs(mid + 1, r));
    int k = 0;
    for (int i = l; i <= r; i ++) {
        LL dx = p[i].first - p[mid].first;
        if (dx * dx < d * d) {
            tmp[k ++] = p[i];
        }
    }
    sort(tmp, tmp + k, [](PII a, PII b) {
        return a.second < b.second;
    });
    for (int i = 0; i < k; i ++) {
        for (int j = i + 1; j < k && (tmp[j].second - tmp[i].second) < d; j ++) {
            d = min(d, dist(tmp[i], tmp[j]));
        }
    }
    return d;
}

int main() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);  
    double ans = dfs(0, n - 1);
    printf("%.2lf", ans);
    return 0;
}