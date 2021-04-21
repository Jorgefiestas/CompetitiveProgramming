#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 3e5 + 10;
const int S = 750;
int n, q, a[N];
vector<int> idx[N];

int count(int x, int r) {
	auto it = upper_bound(idx[x].begin(), idx[x].end(), r);
	return distance(idx[x].begin(), it);
}

int count(int x, int l, int r) {
	return count(x, r) - count(x, l - 1);
}

int calc(int x, int y) {
	if (y <= (x + 1) / 2)
		return 1;
	return 2 * y - x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	random_device rd;
	mt19937 gen(rd());

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idx[a[i]].emplace_back(i);
	}

	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;

		int mf = 0;
		for (int i = 0; i < 40; i++) {
			uniform_int_distribution<int> ud(l, r);
			int x = a[ud(gen)];
			mf = max(mf, count(x, l, r));
		}
		cout << calc(r - l + 1, mf) << '\n';
	}

	return 0;
}
