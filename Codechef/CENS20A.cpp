#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1005;
int n, m, q;
bool mat[N][N], rev[N], toflip[N];
vector<pii> queries[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	char cij;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cij;
			mat[i][j] = (cij == '1');
		}
	}

	cin >> q;

	int xa, xb, ya, yb;
	for (int i = 0; i < q; i++) {
		cin >> xa >> ya >> xb >> yb;
		queries[xa].push_back({ya, yb});
		queries[xb + 1].push_back({ya, yb});
	}

	for (int r = 1; r <= n; r++) {
		memset(toflip, 0, sizeof toflip);
		for (pii flp : queries[r]) {
			toflip[flp.first] = !toflip[flp.first];
			toflip[flp.second + 1] = !toflip[flp.second + 1];
		}
		for (int i = 1; i <= m; i++) {
			toflip[i] ^= toflip[i - 1];
			if (toflip[i]) {
				rev[i] = !rev[i];
			}
		}

		for (int i = 1; i <= m; i++) {
			if (rev[i]) {
				cout << !mat[r][i];
			}
			else {
				cout << mat[r][i];
			}
		}
		cout << '\n';
	}

	return 0;
}
