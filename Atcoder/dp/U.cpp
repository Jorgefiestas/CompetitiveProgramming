#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16) + 50;
int n;
long long mem[N], a[17][17], s[N];
bool vis[N];

long long score(int bm) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (!(bm & (1 << i))) continue;
		for (int j = i + 1; j < n; j++) {
			if (!(bm & (1 << j))) continue;
			ans += a[i][j];
		}
	}
	return ans;
}

long long dp(int bm) {
	if (__builtin_popcount(bm) <= 1) {
		return 0;
	}
	if (vis[bm]) {
		return mem[bm];
	}
	vis[bm] = true;

	long long ans = 0;
	for (int fbm = bm; fbm; fbm = (fbm - 1) & bm) {
		long long tans = s[fbm] + dp(bm & ~fbm);
		ans = max(ans, tans);
	}

	return mem[bm] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i < (1 << n); i++) {
		s[i] = score(i);
	}

	cout << dp((1 << n) - 1) << endl;

	return 0;
}
