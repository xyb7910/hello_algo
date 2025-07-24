#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 5;

string s, s1;
int n, ans, len;
int main(){

    cin >> s >> n;
    len = s.size();
    while(n--){
        cin >> s1;
        bool flag = s1.size() == len;
        for(int i = 0, j = len - 1; i < len && j >= 0; i++, j--)
            if((s[i] >= '0' && s[i] <= '9') != (s1[j] >= '0' && s1[j] <= '9')) flag = 0;
        ans += flag;
    }
    cout << ans;
    return 0;
}