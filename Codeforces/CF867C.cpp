#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 100;
int n, sl, s[N], a[N], b[N];
pii order[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> sl;

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i] >> b[i];
		order[i] = {a[i] - b[i], i};
		sum += (long long) s[i];
	}

	if (sum % sl) {
		s[n] = sl - sum % sl;
		order[n] = {0, n};
		n += 1;
	}

	sort(order, order + n, greater<pii>());

	long long cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (order[i].first > 0) {
			cnt1 += (long long) s[order[i].second];
		}
	}

	long long op[2];
	op[0] = (long long) (cnt1 / sl) * sl;
	op[1] = (long long) ((cnt1 + sl - 1) / sl) * sl;

	long long ans = 0;
	for (int opi = 0; opi < 2; opi++) {
		long long can = 0;
		for (int i = 0; i < n; i++) {
			int idx = order[i].second;
			if (op[opi] - s[idx] >= 0) {
				can += (long long) s[idx] * a[idx];
				op[opi] -= s[idx];
			}
			else if (op[opi] == 0) {
				can += (long long) s[idx] * b[idx];
			}
			else {
				can += (long long) op[opi] * a[idx];
				can += (long long) (s[idx] - op[opi]) * b[idx];
				op[opi] = 0;
			}
		}
		ans = max(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
