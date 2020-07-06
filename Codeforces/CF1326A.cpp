#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;

int solve() {
	if (a < b) {
		swap(a, b);
	}

	int cnt = 0;
	while (a > b) {
		if (a & 1) return -1;
		a >>= 1;
		cnt++;
	}

	if (a < b) {
		return -1;
	}

	return (cnt + 2) / 3;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b;
		cout << solve() << '\n';
	}

	return 0;
}
