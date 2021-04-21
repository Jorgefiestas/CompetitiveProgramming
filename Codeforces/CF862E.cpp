#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q, a[N], b[N];
vector<long long> bsums;

long long query(long long x) {
	auto it = upper_bound(bsums.begin(), bsums.end(), x);
	auto prv = it;

	if (prv != bsums.begin()) {
		prv = prev(prv);
	}

	long long ans = abs(x - *prv);
	if (it != bsums.end()) {
		ans = min(ans, abs(x - *it));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	long long sum = 0, sgn = 1;

	for (int i = 1; i <= n; i++) {
		sum += (long long) sgn * b[i];
		sgn = -sgn;
	}
	sgn = -sgn;

	bsums.emplace_back(sum);
	for (int i = n + 1; i <= m; i++) {
		sum -= (long long) b[i - n];
		sum = (long long) sgn * b[i] - sum;
		bsums.emplace_back(sum);
	}

	sort(bsums.begin(), bsums.end());

	sum = 0, sgn = 1;
	for (int i = 1; i <= n; i++) {
		sum += (long long) sgn * a[i];
		sgn = -sgn;
	}

	cout << query(sum) << '\n';

	int li, ri;
	long long xi;
	for (int qi = 0; qi < q; qi++) {
		cin >> li >> ri >> xi;
		if ((ri - li + 1) % 2) {
			if (li % 2) sum += xi;
			else sum -= xi;
		}

		cout << query(sum) << '\n';
	}

	return 0;
}
