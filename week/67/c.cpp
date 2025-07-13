#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main() {
    cin >> s;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            cnt[c - '0']++;
        }
    }
    bool first = true;
    for (int i = 1; i <= 9; i++) {
        while (cnt[i]--) {
            if (!first) cout << "+";
            cout << i;
            first = false;
        }
    }
    if (first) cout << 0;
    return 0;
}