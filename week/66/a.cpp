#include <bits/stdc++.h>
using namespace std;
int sum;
int main() {
    for (int i = 0; i < 4; i ++) {
        int t; cin >> t;
        sum += t;
    }
    cout << sum / 60 << endl << sum % 60;
    return 0;
}