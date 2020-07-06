#include <bits/stdc++.h>
using namespace std;
int n, m;
set<long long> bms[6];

long long to_bit(string &s) {
	long long x = 0;
	for (long long i = 0; i < n; i++) {
		if (s[i] == '0') continue;
		x |= (1LL << i);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	bms[0].insert(0);
	for (int j = 1; j <= n; j++) {
		for (int i = min(j, 5); i >= 1; i--) {
			for (long long x : bms[i - 1]) {
				bms[i].insert(x | (1LL << (j - 1)));
			}
		}
	}

	int c;
	long long x;
	string s;
	set<long long> poss;

	cin >> s >> c;
	x = to_bit(s);
	
	for (long long bm : bms[c]) {
		poss.insert(~(x ^ bm));
	}

	for (int i = 1; i < m; i++) {
		cin >> s >> c;
		x = to_bit(s);

		set<long long> tposs;
		for (long long bm : bms[c]) {
			if (!poss.count(~(x ^ bm))) continue;
			tposs.insert(~(x ^ bm));
		}

		poss = tposs;
	}

	cout << poss.size() << '\n';

	return 0;
}
