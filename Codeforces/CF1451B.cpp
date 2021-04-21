#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, q;
bool a[N], back[2][N], front[2][N];
string str;

void solve() {
	cin >> n >> q;
	cin >> str;

	for (int i = 1; i <= n; i++) {
		a[i] = str[i - 1] == '1';
	}

	for (int i = 1; i <= n; i++) {
		back[0][i] = back[0][i - 1];
		back[1][i] = back[1][i - 1];
		back[a[i]][i] = true;
	}

	for (int i = n; i >= 1; i--) {
		front[0][i] = front[0][i + 1];
		front[1][i] = front[1][i + 1];
		front[a[i]][i] = true;
	}

	int l, r;
	for (int qi = 0; qi < q; qi++) {
		cin >> l >> r;

		if (back[a[l]][l - 1] || front[a[r]][r + 1]) {
			cout << "YES\n";
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
		memset(back, 0, sizeof back);
		memset(front, 0, sizeof front);
		solve();
	}

	return 0;
}
