#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n[3], a[3][N];
long long sum[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int j = 0; j < 3; j++) {
		cin >> n[j];
	}

	long long tsum = 0;
	long long fsum = 0;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n[j]; i++) {
			cin >> a[j][i];
			sum[j] += (long long) a[j][i];
		}

		sort(a[j], a[j] + n[j]);

		tsum += sum[j];
		fsum += (long long) a[j][0];
	}


	long long ans = 0;
	for (int j = 0; j < 3; j++) {
		long long can1 = tsum - 2 * sum[j];
		long long can2 = tsum - 2 * fsum + 2LL * a[j][0];
		ans = max({ans, can1, can2});
	}
	
	 cout << ans << '\n';

	return 0;
}
