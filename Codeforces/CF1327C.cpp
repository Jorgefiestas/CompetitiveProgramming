#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m, k;
vector<char> moves;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int sx, sy;
	for (int i = 0; i < k; i++) {
		cin >> sx >> sy;
	}
	for (int i = 0; i < k; i++) {
		cin >> sx >> sy;
	}

	for (int i = 1; i < n; i++) {
		moves.push_back('U');
	}
	for (int i = 1; i < m; i++) {
		moves.push_back('L');
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			char move = (i % 2) ? 'L' : 'R';
			moves.push_back(move);
		}
		moves.push_back('D');
	}

	cout << moves.size() << '\n';
	for (char move : moves) {
		cout << move;
	}
	cout << '\n';

	return 0;
}
