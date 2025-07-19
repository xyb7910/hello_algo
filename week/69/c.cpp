#include <bits/stdc++.h>
using namespace std;
bool vis[128];
int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (!vis[tolower(c)]) {
            vis[tolower(c)] = 1;
            cout << (char)toupper(c);
        } else {
            cout << (char)tolower(c);
        }
    }
    return 0;
}