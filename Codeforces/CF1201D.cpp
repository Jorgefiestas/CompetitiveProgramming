#include <bits/stdc++.h>
using namespace std;
using pil = pair<int, long long>;
const int N = 2e5 + 5;
int n, m, k, q;
vector<int> a[N];
set<int> b;

int dist(int s, int m, int l) {
	return abs(m - s) + abs(l - m);
}

int dist(int s, int l) {
	return abs(l - s);
}

int pred(int x) {
	auto it = b.lower_bound(x);
	if (*it == x) {
		return x;
	}
	if (it == b.begin()) {
		return 0;
	}
	it--;
	return *it;
}

int succ(int x) {
	auto it = b.upper_bound(x);
	if (it == b.end()) {
		return 0;
	}
	return *it;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k >> q;
	
	int maxn = 0;
	int minn = n + 1;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x].emplace_back(y);
		maxn = max(x, maxn);
		minn = min(x, minn);
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		b.insert(x);
	}

	long long dr;
	long long dl;
	long long skip = 0;

	int first = 1;
	if (minn > 1) {
		first = *b.begin();
		skip += first - 1;
		skip += minn - 1;
	}

	vector<pil> sps;
	sps.push_back({first, 0});
	for (int i = minn; i <= maxn; i++) {
		if (a[i].empty()) {
			skip++;
			continue;
		}

		for (pil &p : sps) {
			p.second += (long long) skip;
		}
		skip = 0;

		int lm = *min_element(a[i].begin(), a[i].end());
		int rm = *max_element(a[i].begin(), a[i].end());

		dr = LLONG_MAX;
		dl = LLONG_MAX;
		for (pil p : sps) {
			int sp = p.first;
			long long od = p.second;

			if (sp) {
				dl = min(dl, od + (long long) dist(sp, rm, lm));
				dr = min(dr, od + (long long) dist(sp, lm, rm));
			}
		}

		if (i == maxn) {
			break;
		}

		skip++;
		sps.clear();

		int ll = pred(lm);
		sps.push_back({ll, dl + (long long) dist(lm, ll)});
		int lr = succ(lm);
		sps.push_back({lr, dl + (long long) dist(lm, lr)});
		int rl = pred(rm);
		sps.push_back({rl, dr + (long long) dist(rm, rl)});
		int rr = succ(rm);
		sps.push_back({rr, dr + (long long) dist(rm, rr)});
	}

	cout << min(dl, dr) << '\n';

	return 0;
}
