#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;

void solve() {
	cin >> n >> x >> y;

	int dxy = y - x;
	int dif;

	for (int d = n - 1; d > 0; d--) {
		if (dxy % d) continue;
		dif = dxy / d;
		break;
	}

	deque<long long> arr;

	long long z = x;
	while (z <= y) {
		arr.push_back(z);
		z += dif;
	}

	z = x - dif;
	while (z > 0 && arr.size() < n) {
		arr.push_front(z);
		z -= (long long) dif;
	}

	z = y + dif;
	while (arr.size() < n) {
		arr.push_back(z);
		z += (long long) dif;
	}

	for (int x : arr) {
		cout << x << ' ';
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
