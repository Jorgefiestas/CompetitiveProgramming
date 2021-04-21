#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e4 + 10;
int n, m;
char mat[N][M];

void impossible() {
	cout << "Never\n";
	exit(0);
}

map<char, set<int>> idx;

int left(char w, int pos) {
	auto it = idx[w].lower_bound(pos);
	if (!idx[w].empty() && it != idx[w].begin()) {
		return *prev(it);
	}
	return -1;
}

int right(char w, int pos) {
	auto it = idx[w].upper_bound(pos);
	if (it != idx[w].end()) {
		return *it;
	}
	return - 1;
}

long long floor(int f, int &x, bool &dir) {
	idx.clear();

	for (int i = 1; i <= m; i++) {
		if (mat[f][i] == '.' && mat[f + 1][i] == '.') {
			mat[f][i] = 'h';
		}
	}

	for (int i = 0; i <= m + 1; i++) {
		if (mat[f][i] == '.') continue;
		idx[mat[f][i]].insert(i);
	}

	for (int i = 0; i <= m + 1; i++) {
		idx[mat[f][x]].insert(i);
	}


	bool pos = false;
	for (int i = left('#', x) + 1; i < right('#', x); i++) {
		if (mat[f + 1][i] == '.') {
			pos = true;
			break;
		}
	}

	if (!pos) impossible();

	long long time = 0;
	while (mat[f][x] != 'h') {
		if (dir) {
			int b = right('+', x);
			int c = right('#', x);
			int h = right('h', x);

			if (h > 0 && (b < 0 || h < b) && h < c) {
				time += (long long) (h - x);
				x = h;
			}
			else if (b > 0 && b < c) {
				time += (long long) (b - x);
				x = b - 1;
				dir = !dir;

				idx['+'].erase(b);
				if (mat[f + 1][b] == '.') {
					idx['h'].insert(b);
					mat[f][b] = 'h';
				}
			}
			else {
				time += (long long) (c - x);
				x = c - 1;
				dir = !dir;
			}
		}
		else {
			int b = left('+', x);
			int c = left('#', x);
			int h = left('h', x);

			if (h > 0 && (b < 0 || h > b) && h > c) {
				time += (long long) (x - h);
				x = h;
				break;
			}
			else if (b > 0 && b > c) {
				time += (long long) (x - b);
				x = b + 1;
				dir = !dir;

				idx['+'].erase(b);
				if (mat[f + 1][b] == '.') {
					idx['h'].insert(b);
					mat[f][b] = 'h';
				}
			}
			else {
				time += (long long) (x - c);
				x = c + 1;
				dir = !dir;
			}
		}
	}

	return time + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		mat[i][0] = '#';
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
		mat[i][m + 1] = '#';
	}

	int x = 1;
	bool dir = 1;
	long long time = 0;
	for (int flr = 0; flr < n - 1; flr++) {
		time += floor(flr, x, dir);
	}

	cout << time << '\n';

	return 0;
}
