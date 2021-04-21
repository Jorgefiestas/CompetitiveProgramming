#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
const int N = 2e5 + 10;
const int L = 19;
int n, dp[L][L];
long long a[N];

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int cntFact(long long x, long long d) {
	int ans = 0;
	while (x % d == 0) {
		ans += 1;
		x /= d;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	string num;
	char sep;
	long long x;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num.find('.') == string::npos) {
			a[i] = stol(num);
			a[i] *= (long long) 1e9;
			continue;
		}

		string swho = num.substr(0, num.find('.'));
		string sdec = num.substr(num.find('.') + 1);

		while (sdec.size() < 9) {
			sdec += '0';
		}

		long long who = stol(swho);
		long long dec = stol(sdec);

		a[i] = who;
		a[i] *= (long long) 1e9;
		a[i] += dec;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int d2 = min(18, cntFact(a[i], 2));
		int d5 = min(18, cntFact(a[i], 5));

		for (int j = 18 - d2; j < L; j++) {
			for (int k = 18 - d5; k < L; k++) {
				ans += dp[j][k];
			}
		}

		dp[d2][d5] += 1;
	}

	cout << ans << '\n';

	return 0;
}
