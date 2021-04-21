#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 105;
int t, n, k;
pii pt[N];

int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> pt[i].first >> pt[i].second;
	}

	for (int i = 1; i <= n; i++) {
		bool good = true;
		for (int j = 1; j <= n; j++) {
			if (dist(pt[i], pt[j]) > k) 
				good = false;
		}
		if (good) 
			return 1;
	}
	return -1;
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
