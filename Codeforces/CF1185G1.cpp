#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = (1 << 15);
const int mod = 1e9 + 7;
int n, t;
pii song[N];
int mem[N][256][4];
bool vis[N][256][4];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int dp(int bm, int sum, int last) {
	if (sum > t) {
		return 0;
	}
	if (sum == t) {
		return 1;
	}
	if (vis[bm][sum][last]) {
		return mem[bm][sum][last];
	}
	vis[bm][sum][last] = true;

	int ans =  0;
	for (int i = 0; i < n; i++) {
		if (bm & (1 << i)) continue;
		if (song[i].second == last) continue;
		int b = dp(bm | (1 << i), sum + song[i].first, song[i].second);
		ans = add(ans, b);
	}
	
	return mem[bm][sum][last] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> song[i].first >> song[i].second;
	}

	cout << dp(0, 0, 0) << '\n';

	return 0;
}
