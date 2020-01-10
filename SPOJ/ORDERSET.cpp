#include <bits/stdc++.h>
using namespace std;
using pci = pair<char, int>;
const int N = 200000;
int q, st[4 * N + 5], itn[N];
unordered_map<int, int> nti;
set<int> nums;
pci queries[N + 5];

void update(int v, int tl, int tr, int k, int val) {
	if (tl == tr) {
		st[v] = val;
	}
	else {
		int tm = (tl + tr) / 2;
		if (k <= tm) {
			update(v * 2, tl, tm, k, val);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, k, val);
		}
		st[v] = st[v * 2] + st[v * 2 + 1];
	}
}

int kth(int v, int tl, int tr, int k) {
	if (k > st[v]) {
		return -1;
	}
	if (tl == tr) {
		return tl;
	}
	int tm = (tl + tr) / 2;
	if (st[v * 2] < k) {
		return kth(v * 2 + 1, tm + 1, tr, k - st[v * 2]);
	}
	return kth(v * 2, tl, tm, k);
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tr + tl) / 2;
	int ql = query(v * 2, tl, tm, l, min(r, tm));
	int qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return ql + qr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;
	char c;
	int k;
	for(int i = 0; i < q; i++){
		cin >> c >> k;
		if (c != 'K') {
			nums.insert(k);
		}
		queries[i] = {c, k};
	}

	int idx = 0;
	for (int x : nums) {
		nti[x] = idx;
		itn[idx] = x;
		idx++;
	}

	for (pci qu : queries) {
		if (qu.first != 'K') {
			k = nti[qu.second];
		}
		else {
			k = qu.second;
		}
		switch (qu.first) {
			case 'I': {
				update(1, 0, N, k, 1);
				break;
			}
			case 'D': {
				update(1, 0, N, k, 0);
				break;
			}
			case 'K': {
				int qans = kth(1, 0, N, k);
				if (qans == -1) {
					cout << "invalid\n";
				}
				else {
					cout << itn[qans] << '\n';
				}
				break;
			}
			case 'C': {
				cout << query(1, 0, N, 0, k - 1) << '\n';
				break;
			}
		}
	}

	return 0;
}
