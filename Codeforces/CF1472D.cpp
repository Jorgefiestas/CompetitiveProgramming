#include <bits/stdc++.h>
using namespace std;
int t, n;

string solve() {
	cin >> n;

	priority_queue<int> pq[2];

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		pq[x % 2].push(x);
	}

	long long a = 0;
	long long b = 0;

	for (int i = 0; i < n; i++) {
		int emx = pq[0].empty() ? 0 : pq[0].top();
		int omx = pq[1].empty() ? 0 : pq[1].top();

		if (emx > omx) {
			pq[0].pop();
			if (i % 2 == 0) {
				a += emx;
			}
		}
		else {
			pq[1].pop();
			if (i % 2 == 1) {
				b += omx;
			}
		}
	}

	if (a == b) {
		return "Tie";
	}
	return (a > b) ? "Alice" : "Bob";
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
