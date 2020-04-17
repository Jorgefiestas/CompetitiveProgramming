#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int N = 1e7 +  10;
int n, m, a[maxn],  b[maxn], spf[N], cnt[N];
vector<int> numerator, denominator;

void sieve() {
	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < N; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < N; j += i) {
			spf[j]  = min(spf[j], i);
		}
	}
}

void decompose(int x, int val) {
	while (x > 1) {
		cnt[spf[x]] += val;
		x /= spf[x];
	}
}

void mul(long long &x, vector<int> &vec, long long y) {
	if (x * y > 1e7) {
		vec.emplace_back(x);
		x = y;
		return;
	}
	x *= y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		decompose(a[i], 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		decompose(b[i], -1);
	}

	for (int i = 0; i < n; i++) {
		int ans = 1;
		int x = a[i];

		while (x > 1) {
			if (cnt[spf[x]] > 0) {
				ans *= spf[x];
				cnt[spf[x]]--;
			}
			x /= spf[x];
		}

		numerator.emplace_back(ans);
	}
	for (int i = 0; i < m; i++) {
		int ans = 1;
		int x = b[i];

		while (x > 1) {
			if (cnt[spf[x]] < 0) {
				ans *= spf[x];
				cnt[spf[x]]++;
			}
			x /= spf[x];
		}

		denominator.emplace_back(ans);
	}

	cout << n << ' ' << m << '\n';

	for (int a : numerator) {
		cout <<  a << ' ';
	}
	cout << '\n';

	for (int a : denominator) {
		cout <<  a << ' ';
	}
	cout << '\n';

	return 0;
}
