#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, q;
bool mat[3][N];

int blocked = 0;

void update(int r, int c) {
	int ar = (r == 1) ? 2 : 1;
	int d = mat[r][c] ? -1 : 1;

	for (int dc = -1; dc <= 1; dc++) {
		int nc = c + dc;
		if (nc <= 0 || nc > n) continue;
		if (mat[ar][nc]) {
			blocked += d;
		}
	}

	mat[r][c] = !mat[r][c];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	int r, c;
	for (int qi = 0; qi < q; qi++) {
		cin >> r >> c;
		update(r, c);

		if (!blocked) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
