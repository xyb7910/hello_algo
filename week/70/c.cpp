#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
bool ischar(char c) {
    return c >= 'a' && c <= 'z';
}
bool st[N], back_up[N];
int main() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i ++)
        if(isdigit(s[i])) st[i] = 1;
        else if(ischar(s[i])) st[i] = 0; 
    int n, cnt = 0; cin >> n;
    for (int i = 0; i < n; i ++) {
        memset(back_up, 0, sizeof back_up);
        string str; cin >> str;
        if(str.size() != s.size()) continue;
        int l = str.size();
        for (int i = l - 1; i >= 0; i --)
        {
            if(isdigit(str[i])) back_up[i] = 1;
            else if(ischar(str[i])) back_up[i] = 0; 
        }
        int f = 0;
        for (int i = 0, j = l - 1; i < l && j >= 0; i ++, j --)
            if(st[i] ^ back_up[j]) f = 1;
        if(!f) cnt ++; 
    }
    cout << cnt;
    return 0;
}