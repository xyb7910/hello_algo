#include <bits/stdc++.h>
using namespace std;
int main() {
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int A = (a + c - 1) / c; 
    int B = (b + d - 1) / d; 
    int t = max(A, B); 
    cout << l - t << endl;
    return 0;
}