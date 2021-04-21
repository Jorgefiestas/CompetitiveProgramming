#include <bits/stdc++.h>
using namespace std;
const int L = 45;
int n, cnt[L];
vector<long long> caps;

void impossible() {
	cout << -1 << '\n';
	exit(0);
}

int getPow(long long x) {
	int pow = 63 - __builtin_clzll(x);
	if (x != (1LL << pow)) {
		return -1;
	}
	return pow;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int p2 = getPow(a);
		if (p2 == -1) {
			caps.emplace_back(a);
			continue;
		}
		cnt[p2]++;
	}

	for (int p = 1; p < L; p++) {
		while (cnt[p] > cnt[p - 1]) {
			caps.push_back(1LL << p);
			cnt[p]--;
		}
		cnt[p - 1] -= cnt[p];
	}

	sort(caps.rbegin(), caps.rend());

	vector<long long> towers;
	for (int p = 0; p < L; p++) {
		for (int i = 0; i < cnt[p]; i++) {
			towers.push_back(1LL << p);
		}
	}

	if (caps.size() > towers.size()) {
		impossible();
	}

	for (int i = 0; i < caps.size(); i++) {
		if (caps[i] > towers.back() * 2LL) {
			impossible();
		}
		towers.pop_back();
	}

	int mxsize = caps.size() + towers.size();

	int mnsize = mxsize;
	for (int i = 0; i < towers.size(); i++) {
		while (i != towers.size() && towers[i]) {
			towers.pop_back();
			towers[i] >>= 1;
		}

		if (i != towers.size() && !towers[i]) {
			mnsize -= 1;
		}
	}

	for (int i = mnsize; i <= mxsize; i++) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
