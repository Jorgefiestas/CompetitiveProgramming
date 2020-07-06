#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, cnt[N];
string str;

struct Zeta {
	int z[N];

	Zeta() {
		memset(z, 0, sizeof z);
	}

	void build(const string &str) {
		int l = 0, r = 0;
		for (int i = 1; i < str.size(); i++) {
			if (i <= r) {
				z[i] = min(r - i + 1, z[i - l]);
			}
			while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
				z[i]++;
			}
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
	}

	int operator[](int idx) {
		return z[idx];
	}
} z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	n = str.size();

	z.build(str);

	set<int> valid;
	for (int i = 0; i < n; i++) {
		cnt[z[i]]++;
		if (z[i] + i == n) {
			valid.insert(z[i]);
		}
	}

	for (int i = n - 1; i > 0; i--) {
		cnt[i] += cnt[i + 1];
	}

	cout << valid.size() + 1 << '\n';
	for (int v : valid) {
		cout << v << ' ' << cnt[v] + 1 << '\n';
	}
	cout << n << ' ' << 1 << '\n';

	return 0;
}
