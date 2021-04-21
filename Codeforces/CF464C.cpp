#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, dp[N], q[N], sz[N], nxt[26];
string str[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str[0];
	cin >> n;

	string qry;
	for (int i = 1; i <= n; i++) {
		cin >> qry;

		for (int j = 3; j < qry.size(); j++) {
			str[i] += qry[j];
		}

		q[i] = qry[0] - '0';
	}

	for (int i = n; i >= 0; i--) {
		long long pow = 0;

		for (int j = str[i].size() - 1; j >= 0; j--) {
			int c = str[i][j] - '0';

			if (nxt[c] == 0) {
				dp[i] = add(dp[i], mul(c, exp(10, pow)));
				pow = (pow + 1) % (mod - 1);
			}
			else {
				dp[i] = add(dp[i], mul(dp[nxt[c]], exp(10, pow)));
				pow = (pow + sz[nxt[c]]) % (mod - 1);
			}
		}

		sz[i] = pow;
		nxt[q[i]] = i;
	}

	cout << dp[0] << '\n';
}
