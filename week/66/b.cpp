#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool f;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int a, b; cin >> a >> b;
        m += a;
        if(m - b < 0) {
            f = false;
            break;
        } else {
            m -= b;
        }
        ans = max(ans, m);
    }
    if(f) cout << ans;
    else cout << 0;
    return 0;
}