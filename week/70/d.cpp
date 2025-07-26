#include <bits/stdc++.h>
using namespace std;
// author:yanpengbo
const int N = 1e3 + 10;
typedef pair<int, int> PII;
int a[N], res[N];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        vector<PII> dist;
        for (int j = 0; j < n; j ++) {
            if (i != j) dist.push_back({abs(a[i] - a[j]), j + 1});
        }
        sort(dist.begin(), dist.end());
        res[i] = dist[k - 1].second;
    }
    for (int i = 0; i < n; i ++ ) 
        cout << res[i] << " ";
    return 0;
}