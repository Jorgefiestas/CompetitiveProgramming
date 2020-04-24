#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 1e6 + 5;
int n;
long long x, y, cnt[M], acc[M], acci[M];

int findMid(int g) {
	int l = 1;
	int r = g;

	int ans = 0;
	while (l <= r) {
		int mid  = (l + r) / 2;
		if ((g - mid) * 1LL * y > x) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y;

	int ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		cnt[ai]++;
	}

	for (int i = 1; i < M; i++) {
		acc[i] = acc[i - 1] + cnt[i];
		acci[i] = acci[i - 1] + cnt[i] * i;
	}

	long long ans = LLONG_MAX;
	for (long long g = 2; g < M; g++) {
		int mid = findMid(g);
		long long tans = 0;
		int i = 1;
		for (int s = 1; s < M; s += g) {
			int xlim = min((int) (s + mid - 1), M - 1);
			int ylim = min((int) (s + g - 1), M - 1);
			long long xcnt = acc[xlim] - acc[s - 1];
			long long ycnt = acc[ylim] - acc[xlim];
			long long ycnti = acci[ylim] - acci[xlim];

			long long xsum = xcnt * x;
			long long ysum = y * (ycnt * g * i - ycnti);

			tans += xsum + ysum;
			i++;
		}
		ans = min(ans, tans);
	}

	cout << ans << endl;

}
