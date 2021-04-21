#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, a, b, k, h[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h[i] = h[i] % (a + b);
		if (!h[i]) {
			h[i] = a + b;
		}
	}

	int ans = 0;
	vector<int> toWin;

	for (int i = 0; i < n; i++) {
		if (h[i] <= a) {
			ans += 1;
		}
		else {
			toWin.push_back((h[i] - 1) / a);
		}
	}

	sort(toWin.begin(), toWin.end());

	for (int i = 0; i < toWin.size(); i++) {
		if (toWin[i] > k) break;
		k -= toWin[i];
		ans += 1;
	}

	cout << ans << '\n';

	return 0;
}
