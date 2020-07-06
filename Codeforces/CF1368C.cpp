#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
set<pii> points;

const int dx[] = {0, 0, 0, 1, 2, 2, 2, 1};
const int dy[] = {0, 1, 2, 2, 2, 1, 0, 0};

void makeSquare(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		points.insert({nx, ny});
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	makeSquare(0, 0);

	int sx = 2;
	int sy = 2;
	for (int i = 0; i < n; i++) {
		makeSquare(sx, sy);
		sy += (i % 2) ? 2 : -2;
		sx += 2;
	}

	cout << points.size() << '\n';
	for (pii p : points) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}
