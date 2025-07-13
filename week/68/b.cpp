#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum; scanf("%d", &sum);
    for (int i = 0; i < 9; i ++)
    {
        int x; scanf("%d", &x);
        sum -= x;
    }
    printf("%d", sum);
    return 0;
}