#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, cnt[45];
vector<long long> towers;
vector<long long> flt;

int imp() {
	cout << -1 << '\n';
	exit(0);
}

bool extractp2(int p) {
	for (int i = 0; i <= p; i++) {
		if (!cnt[i]) return false;
	}

	for (int i = 0; i <= p; i++) {
		cnt[i]--;
	}

	towers.push_back(1LL << p);
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if ((a & (a - 1)) == 0) {
			int p2 = 63 - __builtin_clzll(a);
			cnt[p2] += 1;
		}
		else {
			flt.emplace_back(a);
		}
	}

	for (int i = 40; i >= 0; i--) {
		while (extractp2(i));
		for (int j = 0; j < cnt[i]; j++) {
			flt.push_back(1LL << i);
		}
	}

	sort(flt.rbegin(), flt.rend());

	int idx = 0;
	for (long long x : flt) {
		if (idx >= towers.size() || x > 2LL * towers[idx]) {
			imp();
		}
		idx += 1;
	}

	int r = towers.size();
	int l = r;

	for (int i = (int) towers.size() - 1; i > idx; i--) {
		while (i > idx && towers[i]) {
			idx += 1;
			towers[i] >>= 1;
		}
		if (!towers[i]) {
			l -= 1;
		}
	}

	for (int i = l; i <= r; i++) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
