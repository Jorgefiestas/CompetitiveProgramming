#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int n;
bool mat[N][N];
bool r1[N];
bool br1[N], br2[N];
bool abr1[N], abr2[N];
bool cr1[N], cr2[N];
 
inline int uncode(char c) {
	return 10 + c - 'A';
}

void read() {
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < n) {
			char coded;
			cin >> coded;
			if (coded == ' ' || coded == '\n') continue;

			int b4;
			if (coded <= '9') b4 = coded - '0';
			else b4 = coded - 'A' + 10;
			
			for (int b = 3; b >= 0; b--, j++) {
				mat[i][j] = !!(b4 & (1 << b));
			}
		}
	}
}
 
int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		r1[i] = rng() & 1;
	}

	read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			br1[i] = br1[i] ^ (mat[j][i] & r1[j]);
			br2[i] = br2[i] ^ mat[j][i];
		}
	}

	read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			abr1[i] = abr1[i] ^ (mat[j][i] & br1[j]);
			abr2[i] = abr2[i] ^ (mat[j][i] & br2[j]);
		}
	}

	read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cr1[i] = cr1[i] ^ (mat[j][i] & r1[j]);
			cr2[i] = cr2[i] ^ mat[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (abr1[i] != cr1[i] || abr2[i] != cr2[i]) {
			cout << "NO\n";
			return 0;
		}
	}
 
	cout << "YES\n";
 
	return 0;
}
