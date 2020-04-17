#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int t, n, sum[N];

void sieve() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			sum[j] += i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> t;

	while (t--) {
		cin >> n;
		cout << sum[n] << '\n';
	}

	return 0;
}
