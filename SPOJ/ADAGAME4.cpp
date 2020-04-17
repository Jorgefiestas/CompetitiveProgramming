#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
int spf[N];
bool dp[N];

int divisors(int x) {
	int ans = 1;

	while (x > 1) {
		int cnt = 1;
		int d = spf[x];

		while (x % d == 0) {
			cnt++;
			x /= d;
		}
		ans *= cnt;
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < N; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < N; j += i) {
			spf[j] = min(spf[j], i);
		}
	}

	int last = 0;
	for (int h = 1; h < N; h++) {
		if (h - divisors(h) <= last) {
			dp[h] = true;
		}
		else {
			last = h;
		}
	}

	int t, q;

	cin >> t;

	while (t--) {
		cin >> q;
		if (dp[q]) {
			cout << "Ada" << '\n';
		}
		else {
			cout << "Vinit" << '\n';
		}
	}

	return 0;
}
