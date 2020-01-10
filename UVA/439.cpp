#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int k[8][8];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2 , 1, -1, -2, -2, -1};

int BFS(pii s, pii e) {
	queue<pii> Q;

	Q.push(s);
	while (!Q.empty()) {
		pii v = Q.front();
		Q.pop();
		if (v == e) {
			break;
		}

		for (int i = 0; i < 8; i ++) {
			int nx = v.first + dx[i];
			int ny = v.second + dy[i];

			if (nx < 8 && nx >= 0 && ny >= 0 && ny < 8 && !k[nx][ny]) {
				k[nx][ny] = k[v.first][v.second] + 1;
				Q.push({nx, ny});
			}
		}
	}

	return k[e.first][e.second];
}

int main() {
	char x1, x2;
	int y1, y2;

	while (cin >> x1 >> y1 >> x2 >> y2) {
		memset(k , 0 , sizeof k);

		pii s = {x1 - 'a', y1 - 1};
		pii e = {x2 - 'a', y2 - 1};

		cout << "To get from " << x1 << y1 << " to " << x2 << y2 << " takes " << BFS(s, e) << " knight moves." << '\n';
	}

	return 0;
}
