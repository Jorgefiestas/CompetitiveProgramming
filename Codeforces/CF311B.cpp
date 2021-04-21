#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ld = long double;
const int N = 2e5 + 10;
int n, m, p, d[N];
long long f[N], s[N], dp[N][105];
 
struct Sol {
	long long m, c;
 
	long long eval(long long x) {
		return m * x + c;
	}
 
	ld cut(const Sol &eq) {
		long long num = eq.c - c;
		long long den = m - eq.m;
		return (ld) num / den;
	}
};
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m >> p;
	p = min(p, m);
 
	for (int i = 2; i <= n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
 
	int hi, ti;
	for (int i = 1; i <= m; i++) {
		cin >> hi >> ti;
		f[i] = ti - d[hi];
	}
 
	sort(f + 1, f + m + 1);
 
	for (int i = 1; i <= m; i++) {
		s[i] = s[i - 1] + f[i];
		dp[i][1] = f[i] * i - s[i];
	}
 
	for (int j = 2; j <= p; j++) {
		deque<Sol> dq;
		for (int i = j; i <= m; i++) {
			Sol nsol = {-i + 1, dp[i - 1][j - 1] + s[i - 1]};

			int sz = dq.size();
			while (sz > 1 && dq[sz - 2].cut(dq[sz - 1]) > dq[sz - 2].cut(nsol)) {
				dq.pop_back();
				sz--;
			}
 
			dq.push_back(nsol);
 
			while (dq.size() > 1 && dq[0].eval(f[i]) > dq[1].eval(f[i]))
				dq.pop_front();
 
			long long ki = i * f[i] - s[i];
			dp[i][j] = ki + dq.front().eval(f[i]);
		}
	}

	cout << dp[m][p] << '\n';
 
	return 0;
}

