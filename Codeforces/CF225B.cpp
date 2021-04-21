#include <bits/stdc++.h>
using namespace std;
const int L = 60;
int k;
long long s, f[L + 10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> k;

	f[0] = 1;
	for (int i = 1; i <= L; i++) {
		int s = max(0, i - k);
		for (int j = s; j < i; j++) {
			f[i] += f[j];
		}
	}

	vector<int> res;
	while (s) {
		int mn = 0;
		while (f[mn + 1] <= s) {
			mn += 1;
		}

		s -= f[mn];
		res.emplace_back(f[mn]);
	}
	res.emplace_back(0);

	cout << res.size() << '\n';
	for (int x : res) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
