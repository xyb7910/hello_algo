#include <bits/stdc++.h>
using namespace std;
int a[20], b[20];
int main() {
    for (int i = 0; i < 10; i ++) cin >> a[i];
    for (int i = 0; i < 10; i ++) cin >> b[i];
    sort(a, a + 10);
    sort(b, b + 10);
    cout << a[7] + a[8] + a[9] << " ";
    cout << b[7] + b[8] + b[9]; 
    return 0;
}