#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    for (int i = 0; i < 5; i ++) cin >> a[i];
    sort(a, a + 3);
    sort(a + 3, a + 5);
    cout << a[0] + a[3] - 50;
    return 0;
}