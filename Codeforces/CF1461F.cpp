#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long INF = 1e16;
int n, a[N];
char symb[N];
string s;

int trivial() {
	for (int i = 1; i < n; i++) {
		cout << a[i] << s[0];
	}
	cout << a[n] << '\n';
	return 0;
}

int easy() {
	fill(symb, symb + n, '*');

	for (int i = 1; i <= n; i++) {
		if (a[i]) continue;
		symb[i - 1] = '-';
		break;
	}

	for (int i = 1; i < n; i++) {
		cout << a[i] << symb[i];
	}
	cout << a[n] << '\n';

	return 0;
}

void solve(int l, int r) {
	if (l > r) return;

	while (a[l] == 1) {
		symb[l] = '+';
		l += 1;
	}
	while (a[r] == 1) {
		r -= 1;
		symb[r] = '+';
	}

	vector<int> big;

	long long mul = 1;
	for (int i = l; i <= r && mul < INF; i++) {
		mul *= (long long) a[i];

		if (a[i] > 1)
			big.emplace_back(i);
	}

	if (mul >= INF) {
		for (int i = l; i < r; i++) {
			symb[i] = '*';
		}
		return;
	}

	int m = big.size();

	vector<long long> dp;
	vector<int> tran;
	dp.push_back(0);

	for (int i = 0; i < m; i++) {
		dp.push_back(0LL);
		tran.push_back(-1);

		long long mul = 1;
		for (int j = i; j >= 0; j--) {
			mul *= (long long) a[big[j]];

			long long sum = 0;
			if (j > 0) 
				sum = (long long) big[j] - 1 - big[j - 1];

			long long temp = mul + sum + dp[j];

			if (temp > dp[i + 1]) {
				dp[i + 1] = temp;
				tran[i] = j;
			}
		}
	}

	int idx = m - 1;
	while (idx > 0) {
		int pp = N;
		if (tran[idx] > 0)
			pp = big[tran[idx] - 1];

		int sp = big[tran[idx]];
		int ep = big[idx];

		for (int i = sp; i < ep; i++) {
			symb[i] = '*';
		}
		for (int i = pp; i < sp; i++) {
			symb[i] = '+';
		}

		idx = tran[idx] - 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> s;

	if (s.size() == 1) {
		return trivial();
	}
	if (find(s.begin(), s.end(), '*') == s.end()) {
		s = "+";
		return trivial();
	}
	if (find(s.begin(), s.end(), '+') == s.end()) {
		return easy();
	}

	int lst = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i]) continue;
		solve(lst, i - 1);
		symb[i - 1] = '+';
		symb[i] = '+';
		lst = i + 1;
	}
	solve(lst, n);

	for (int i = 1; i < n; i++) {
		cout << a[i] << symb[i];
	}
	cout << a[n] << '\n';

	return 0;
}
