#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, a[N], fact[N];
bool off[32];

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int solve() {
	int n;
	cin >> n;
	
	memset(off, 0, sizeof off);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		for (int bi = 0; bi < 31; bi++) {
			if (a[i] & (1 << bi)) continue;
			off[bi] = true;
		}
	}

	int bord = 0;
	for (int i = 1; i <= n; i++) {
		bool good = true;
		for (int bi = 0; bi < 31; bi++) {
			if (off[bi] && (a[i] & (1 << bi))) {
				good = false;
				break;
			}
		}

		if (good) bord++;
	}

	int ans = mul(bord, bord - 1);
	ans = mul(ans, fact[n - 2]);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
	}

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
