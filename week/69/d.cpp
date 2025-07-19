#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int ans[N][N], n, m;
int main() {
    scanf("%d%d", &n, &m);
    vector<int> nums;
    int num; while(cin >> num) nums.push_back(num);
    for (int k = 0, r = 0, c = 0, g = 0; k < nums.size(); k ++)
    {
        for (int i = 0; i < nums[k] && r < n; i ++)
        {
            ans[r][c] = g;
            if(++ c >= m) c = 0, ++ r;
        }
        g ^= 1;
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}