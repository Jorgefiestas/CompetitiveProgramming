#include <bits/stdc++.h>
using namespace std;
long long a[17];

int solve(long long n) {
	if (n <= 11) {
		return min(13 - n, n);
	}
	
	int i = upper_bound(a, a + 17, n) - a;
	int ans = (n / a[i - 1]) * (i - 1) + solve(n % a[i - 1]);
	if (a[i] - n < n) {
		ans = min(ans, i + solve(a[i] - n));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	long long m = 0;
	for (int i = 0; i <= 16; i++) {
		a[i] = m;
		m *= 10;
		m++;
	}

	cout << solve(n) << '\n';

	return 0;
}
