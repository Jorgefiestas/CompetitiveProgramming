#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e3 + 10;
int n, m;
char mat[N][N];
vector<pii> white;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'w') {
				white.push_back({i, j});
			}
		}
	}

	int mxx = 0, mnx = INT_MAX;
	int mxy = 0, mny = INT_MAX;

	for (auto [i, j] : white) {
		mnx = min(mnx, i);
		mxx = max(mxx, i);
		mny = min(mny, j);
		mxy = max(mxy, j);
	}

	int len = max(mxx - mnx, mxy - mny) + 1;
	cout << len << endl;

	if (len > n || len > m) {
		cout << -1 << '\n';
		return 0;
	}

	return 0;
}
