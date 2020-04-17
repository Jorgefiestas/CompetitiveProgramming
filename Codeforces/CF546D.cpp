#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int t, a, b;
int spf[N], sum[N];

void sieve() {
	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}
	
	for (int i = 2; i * i < N; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < N; j += i) {
			spf[j] = min(spf[j], i);
		}
	}
}

int count(int x) {
	int cnt = 0;
	while (x > 1) {
		cnt++;
		x /= spf[x];
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	for (int i = 2; i < N; i++) {
		sum[i] = sum[i - 1] + count(i);
	}

	cin >> t;

	while (t--) {
		cin >> a >> b;
		cout << sum[a] - sum[b] << '\n';
	}

	return 0;
}
