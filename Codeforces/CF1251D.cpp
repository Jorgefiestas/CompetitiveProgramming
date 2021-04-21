#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 100;
int t, n;
long long s, mn[N], mx[N];

bool check(long long m) { 
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	long long ns = s;
	int ls = 0;
	int gr = 0;

	for (int i = 0; i < n; i++) {
		if (mn[i] <= m && m <= mx[i]) {
			pq.push(mn[i]);
		}
		if (mx[i] < m) {
			ns -= mn[i];
			ls += 1;
		}
		if (m < mn[i]) {
			ns -= mn[i];
			gr += 1;
		}
	}

	if (gr > n / 2) {
		return true;
	}
	if (ls > n / 2) {
		return false;
	}

	while (ls < n / 2) {
		ns -= pq.top();
		pq.pop();
		ls += 1;
	}
	while (gr < n / 2 + 1) {
		ns -= m;
		gr += 1;
	}

	return ns >= 0;
}

long long solve() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> mn[i] >> mx[i];
	}

	long long l = 0;
	long long r = s;

	long long ans = 0;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (check(m)) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
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
