#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, d, m;
vector<int> cheap, expen;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> m;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > m) {
			expen.emplace_back(a);
		}
		else {
			cheap.emplace_back(a);
		}
	}

	sort(expen.begin(), expen.end(), greater<int>());
	sort(cheap.begin(), cheap.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		expen.push_back(0);
		cheap.push_back(0);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cheap[i];
	}
	int cidx = n - 1;

	long long mx = ans;
	for (int ex = 1; ex <= n; ex++) {
		int rc = n - (ex - 1) * (d + 1) - 1;

		if (rc < 0) {
			break;
		}
		
		while (cidx >= rc) {
			ans -= cheap[cidx];
			cidx -= 1;
		}
		ans += expen[ex - 1];

		mx = max(ans, mx);
	}

	cout << mx << '\n';

	return 0;
}
