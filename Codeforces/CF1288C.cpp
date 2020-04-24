#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, mem[2][11][1005];
bool vis[2][11][1005];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) (x * 1LL * y) % mod;
}

int dp(int arr, int idx, int a) {
	if (idx == m - 1) {
		return 1;
	}
	if (vis[arr][idx][a]) {
		return mem[arr][idx][a];
	}
	vis[arr][idx][a] = true;

	int d = arr ? -1 : 1;
	int ans = 0;
	for (int b = a; b <= n && b >= 1; b += d) {
		ans = add(ans, dp(arr, idx + 1, b));
	}

	return mem[arr][idx][a] = ans;
}

int main() {
	cin >> n >> m;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) { 
			ans = add(ans, mul(dp(0, 0, i), dp(1, 0, j)));
		}
	}

	cout << ans << '\n';

	return 0;
}
