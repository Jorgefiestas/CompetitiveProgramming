#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const int N = 2e5 + 10;
int t, n, m;
vector<pii> v;
long long a[N], sum, mx;

long long query(long long x) {
	long long it = 0;

	if (sum <= 0 && mx < x) {
		return -1;
	}

	long long sv = x;
	long long ans = 0;
	
	if (sum > 0) {
		long long it = max(0LL, (x - mx + sum - 1) / sum);
		ans += (long long) it * n;
		sv -= it * sum;
	}

	ans += upper_bound(v.begin(), v.end(), make_pair(sv, -1))->second;
	return ans - 1;
}

void solve() {
	cin >> n >> m;

	v.clear();
	v.push_back({0, 0});

	mx = LLONG_MIN;
	sum = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, sum);

		if (sum > v.back().first) {
			v.push_back({sum, i});
		}
	}

	long long x;
	for (int qi = 0; qi < m; qi++) {
		cin >> x;
		cout << query(x) << ' ';
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
