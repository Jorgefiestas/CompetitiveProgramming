#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, p4[17], mat[N][N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int lcm = 1;
	for (int i = 2; i <= 16; i++) {
		lcm = (long long) lcm * i / gcd(lcm, i);
	}

	for (int i = 1; i <= 16; i++) {
		p4[i] = i * i * i * i;
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) % 2) {
				cout << lcm + p4[mat[i][j]] << ' ';
			}
			else {
				cout << lcm << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
