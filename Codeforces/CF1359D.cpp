#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
long long n, x, d[N];

long long sum(long long l, long long r) {
	return (l + r) * (r - l + 1) / 2LL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
		d[n + i] = d[i];
	}

	int r = 1;
	long long days = d[0];
	long long tans = sum(1, d[0]);
	long long ans = 0;
	for (int l = 0; l < n; l++) {
		while (days < x) {
			days += d[r];
			tans += sum(1, d[r]);
			r++;
		}

		long long off = days - x;
		ans = max(ans, tans - sum(1, off));
		days -= d[l];
		tans -= sum(1, d[l]);
	}

	cout << ans << '\n';
	
	return 0;
}
