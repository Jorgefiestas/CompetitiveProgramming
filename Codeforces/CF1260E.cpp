#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 5;
const int LOGN = 19;
int n, logn, a[N], num[LOGN + 1];
long long mem[N][LOGN + 1];
bool vis[N][LOGN + 1];

long long dp (int i, int cnt) {
	if (vis[i][cnt]) {
		return mem[i][cnt];
	}
	if (a[i] == -1) {
		return 0;
	}

	vis[i][cnt] = true;

	long long ans = LLONG_MAX;

	if (cnt < logn) {
		ans = (long long) dp(i + 1, cnt + 1) + a[i];
	} 

	if (num[cnt] - i > 0) {
		ans = min(ans, dp(i + 1, cnt));
	}

	return mem[i][cnt] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; (1 << i) <= n; i++) {
		num[i] = num[i - 1] + n / (1 << i);
		logn = i;
	}

	reverse(a, a + n);
	cout << dp(0, 0) << endl;

	return 0;
}
