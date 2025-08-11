#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, k;
int nums[N], used[N];

void dfs(int u) {
	if(u > k) {
		for (int i = 1; i <= k; i ++)
			printf("%5d",nums[i]);
		puts("");
		return ;
	}

	for (int i = 1; i <= n; i ++) {
		if(!used[i]) {
			used[i] = 1;
			nums[u] = i;
			dfs(u + 1);
			used[i] = 0; 
		}
	}
}

int main() {
	cin >> n >> k;
	dfs(1);
	return 0;
}