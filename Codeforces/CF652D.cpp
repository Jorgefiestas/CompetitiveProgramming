#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int  maxn = 2000005;
int n, res[200005], ft[maxn];
unordered_map<int, int> idx;
pii seg[200005];

void update(long long i, int v) {
	while (i < maxn) {
		ft[i] += v;
		i += i & -i;
	}
};

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += ft[i];
		i -= i & -i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		seg[i].first = a;
		seg[i].second = b;
		idx[a] = i;
	}

	sort(seg, seg + n, [](pii x, pii y){return x.second < y.second;});

	for (int i = 1; i <= n; i ++) {
		seg[i - 1].second = i;
	}

	sort(seg, seg + n);

	for (int i = 0; i < n; i ++) {
		update(seg[i].second, 1);
	}

	for (int i = 0; i < n; i ++) {
		res[idx[seg[i].first]] = query(seg[i].second - 1);
		update(seg[i].second, -1);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}
