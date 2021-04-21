#include <bits/stdc++.h>
using namespace std;
int q;
string s, t;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

string solve() {
	cin >> s >> t;

	if (s.size() < t.size()) {
		swap(s, t);
	}

	int n = s.size();
	int m = t.size();
	int lcm = m * n / gcd(n, m);

	string ans;
	for (int i = 0; i < lcm; i++) {
		if (s[i % n] != t[i % m])
			return "-1";
		ans += s[i % n];
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;
	while (q--) {
		cout << solve() << '\n';
	}

	return 0;
}
