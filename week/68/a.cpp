#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; scanf("%d%d", &a, &b);
    string as = to_string(a), bs = to_string(b);
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    if(as == bs) printf("%d", a + b);
    else printf("0");
    return 0;
}