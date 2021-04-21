#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, k, a, b, pos[N];

int count(int val) {
	int ub = upper_bound(pos, pos + k, val) - pos;
	return max(ub, 0);
}

int count(int l, int r) {
	return count(r) - count(l - 1);
}

long long solve(int l, int r) {
	int cnt = count(l, r);
	int len = r - l + 1;
	if (cnt == 0) {
		return a;
	}

	long long ans1 = (long long) cnt * b * len;

	long long ans2 = LLONG_MAX;
	if (len > 1) {
		int mid = (l + r) / 2;
		ans2 = solve(l, mid) + solve(mid + 1, r);
	}

	return min(ans1, ans2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> a >> b;

	for (int i = 0; i < k; i++) {
		cin >> pos[i];
	}

	sort(pos, pos + k);

	cout << solve(1, 1 << n) << '\n';

	return 0;
}
