#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 100;
int m, n, t, a, b;
pii arr[N];

int solve() {
	cin >> n >> t >> a >> b;

	int cnt[2] = {0, 0};

	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
		cnt[arr[i].second] += 1;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
	}

	sort(arr, arr + n);
	arr[n] = {t + 1, 0};

	int ans = 0;
	long long used = 0;

	for (int i = 0; i <= n; i++) {
		int ti = arr[i].first - 1;

		if (ti >= used) {
			int rt = ti - used;

			int na = min(rt / a, cnt[0]);
			rt -= na * a;

			int nb = min(rt / b, cnt[1]);

			ans = max(ans, i + na + nb);
		}

		used += (long long) arr[i].second ? b : a;
		cnt[arr[i].second] -= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	while (m--) {
		cout << solve() << '\n';
	}

	return 0;
}
