#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    int diff = abs(a - b);
    if(diff <= 1)
        cout << 0;
    else 
        cout << diff - 1;
    return 0;
}