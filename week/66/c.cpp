#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main() {
    string s;
    while(cin >> s) {
        int l = s.size();
        for (int i = 0; i < 30; i ++) cnt[i] = 0;
        if(l > 3) {
            cout << s[0];
            for (int i = 1; i < l - 1; i ++) cnt[s[i] - 'a'] ++;
            int maxv = -1;
            for (int i = 0; i < 26; i ++) 
                if(cnt[maxv] < cnt[i]) {
                    maxv = i;
                }
            char c = 'a' + maxv;
            cout << c;
            cout << s[l - 1] << " ";
        } else {
            cout << s << " ";
        }
    }
}