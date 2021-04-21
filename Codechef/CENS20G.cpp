#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, q, sx, sy;
string str;

map<char, int> cnt;

int query(int x, int y) {
	int dx = abs(x - sx);
	int dy = abs(y - sy);

	if (sx > x && cnt['L'] < dx) {
		return -1;
	}
	else if (sx < x && cnt['R'] < dx) {
		return -1;
	}

	if (sy > y && cnt['D'] < dy) {
		return -1;
	}
	else if (sy < y && cnt['U'] < dy) {
		return -1;
	}

	return dx + dy;
}

void solve() {
	cin >> str;
	cin >> sx >> sy;

	for (char x : str) {
		cnt[x] += 1;
	}

	cin >> q;
	int xi, yi;
	for (int i = 0; i < q; i++) {
		cin >> xi >> yi;
		int ans = query(xi, yi);
		if (ans != -1) {
			cout << "YES " << ans << '\n';
		}
		else {
			cout << "NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cnt.clear();
		solve();
	}

	return 0;
}
