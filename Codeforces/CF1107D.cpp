#include <bits/stdc++.h>
using namespace std;
const int N = 5205;
int n;
string mat[N];
char comp[N][N];

bool check(int x) {

	for (int i = 0; i * x < n; i++) {
		for (int j = 0; j * x < n; j++) {
			comp[i][j] = mat[i * x][j * x];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != comp[i / x][j / x]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	char hx, dec;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n >> 2); j++) {
			cin >> hx;
			if (hx <= '9') {
				dec = hx - '0';
			}
			else {
				dec = 10 + hx - 'A';
			}

			mat[i] += bitset<4>(dec).to_string();
		}
	}

	int x = 1;
	int tn = n;
	for (int d = 2; d * d <= tn; d++) {
		if (tn % d) continue;
		while (tn % d == 0) {
			if (check(x * d)) {
				x *= d;
			}
			tn /= d;
		}
	}
	if (check(x * tn)) {
		x *= tn;
	}

	cout << x << '\n';

	return 0;
}
