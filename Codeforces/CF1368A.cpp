#include <bits/stdc++.h>
using namespace std;
int t, a, b, n;

int solve() {
	cin >> a >> b >> n;

	int cnt = 0;
	while (a <= n && b<= n) {
		if (a > b) {
			swap(a, b);
		}

		a += b;
		cnt++;
	}

	return cnt;
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
