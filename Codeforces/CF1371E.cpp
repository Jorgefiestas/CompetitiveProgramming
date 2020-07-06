#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, p, a[N];
vector <int> res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;

	map<int, int> cnt;
	int mx = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(a[i], mx);
		cnt[a[i]] += 1;
	}

	sort(a + 1, a + n + 1);

	int sp = max(a[1], a[n] - n + 1);
	
	int csum = 0;
	map<int, int> open, close;

	for (int i = n; i > 0; i--) {
		if (a[i] == a[i + 1]) continue;
		int pnum = n - csum - a[i];
		int len = cnt[a[i]];
		csum += cnt[a[i]];

		cout << p - pnum << ' ' << p - pnum + len - 1 << endl;
		if (p - pnum < sp && p + len - pnum - 1 >= sp) {
			open[sp] += 1;
		}
		else {
			open[p - pnum] += 1;
		}
		close[p + len - pnum - 1] += 1;

	}

	int j = 1;

	int poss = 0;
	for (int i = sp; i < a[n]; i++) {
		poss += open[i];
		while (a[j + 1] <= i) {
			j += 1;
		}

		int lte = j;
		cout << i << ' ' << poss << ' ' << lte << endl;
		if (lte < p && poss == 0) {
			res.emplace_back(i);
		}

		poss -= close[i];
	}

	cout << res.size() << '\n';
	for (int x : res) {
		cout << x << '\n';
	}

	return 0;
}
