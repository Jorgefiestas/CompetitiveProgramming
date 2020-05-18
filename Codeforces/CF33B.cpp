#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
unordered_map<char, unordered_map<char, int>> cost;

int fail() {
	cout << - 1 << '\n';
	return 0;
}

int price(char x, char y) {
	if (!cost.count(x) || !cost[x].count(y)) {
		return INT_MAX;
	}
	return cost[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t >> n;

	int w;
	char a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> w;
		cost[a][b] = min(w, price(a, b));
	}

	if (s.size() != t.size()) {
		return fail();
	}

	for (char v = 'a'; v <= 'z'; v++) {
		cost[v][v] = 0;
	}

	for (char k = 'a'; k <= 'z'; k++) {
		for (char v = 'a'; v <= 'z'; v++) {
			for (char u = 'a'; u <= 'z'; u++) {
				int p1 = price(v, k);
				int p2 = price(k, u);
				if (p1 == INT_MAX || p2 == INT_MAX) continue;
				cost[v][u] = min(price(v, u), p1 + p2);
			}
		}
	}

	int ans = 0;
	string res = s;
	for (int i = 0; i < s.size(); i++) {
		a = s[i];
		b = t[i];

		int mn = INT_MAX;
		char can;
		for (char v = 'a'; v <= 'z'; v++) {
			int c1 = price(a, v);
			int c2 = price(b, v);

			if (c1 == INT_MAX || c2 == INT_MAX) continue;
			int tans = c1 + c2;

			if (tans < mn) {
				mn = tans;
				can = v;
			}
		}

		if (mn == INT_MAX) {
			return fail();
		}

		ans += mn;
		res[i] = can;
	}

	cout << ans << '\n';
	cout << res << '\n';

	return 0;
}
