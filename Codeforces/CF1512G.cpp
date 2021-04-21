#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int ans[N], d[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(ans, ans + N, -1);

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			d[j] += i;
		}
	}

	for (int i = N - 1; i > 0; i--) {
		if (d[i] >= N) continue;
		ans[d[i]] = i;
	}

	int t;
	cin >> t;

	int c;
	while (t--) {
		cin >> c;
		cout << ans[c] << '\n';
	}

	return 0;
}
