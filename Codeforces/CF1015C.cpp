#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, dif[N];
long long m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	long long tm = 0;
	int ai, bi;
	for (int i = 0; i < n; i++) {
		cin >> ai >> bi;
		dif[i] = bi - ai;
		tm += (long long) ai;
	}

	sort(dif, dif + n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (tm <= m || dif[i] >= 0) break;
		tm += (long long) dif[i];
		cnt++;
	}

	if (tm > m) {
		cout << -1 << '\n';
		return 0;
	}

	cout << cnt << '\n';

	return 0;
}
