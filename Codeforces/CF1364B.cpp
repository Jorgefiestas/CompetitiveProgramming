#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, p[N];
bool skip[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	skip[0] = false;
	skip[n - 1] = false;

	int cnt = 2;
	for (int i = 1; i < n - 1; i++) {
		skip[i] = false;
		if (p[i - 1] <= p[i] && p[i] <= p[i + 1]) {
			skip[i] = true;
		}
		else if (p[i - 1] >= p[i] && p[i] >= p[i + 1]) {
			skip[i] = true;
		}
		else {
			cnt++;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < n; i++) {
		if (skip[i]) continue;
		cout << p[i] << ' ' ;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
