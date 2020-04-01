#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, k;
int cnt[N][30], sum[N];
string s;

int solve() {
	cin >> n >> k >> s;

	for (int i = 0; i < (k + 1) / 2; i++) {
		for (int j = i; j < n; j += k) {
			int c = s[j] - 'a';
			cnt[i][c]++;
			sum[i]++;
		}

		if (i == k - 1 - i) continue;

		for (int j = k - 1 - i; j < n; j += k) {
			int c = s[j] - 'a';
			cnt[i][c]++;
			sum[i]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < (k + 1) / 2; i++) {
		int mx = 0;
		for (int j = 0; j < 26; j++) {
			mx = max(mx, cnt[i][j]);
			cnt[i][j] = 0;
		}
		ans += sum[i] - mx;
		sum[i] = 0;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}
	
	return 0;
}
