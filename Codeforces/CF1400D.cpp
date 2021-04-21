#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int t, n, a[N], cntL[N], cntR[N];

long long solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = 0;

	map<int, int> cntL;
	for (int j = 0; j < n - 1; j++) {
		map<int, int> cntR;
		for (int k = n - 1; k > j; k--) {
			ans += (long long) cntL[a[k]] * cntR[a[j]];
			cntR[a[k]] += 1;
		}

		cntL[a[j]] += 1;

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
