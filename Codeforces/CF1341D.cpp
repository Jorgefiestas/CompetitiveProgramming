#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, k, a[N];
int mem[N][N], nxt[N][N];
bool vis[N][N];

const int num[] = { 
	0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 
	0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011
};

inline int diff(int x, int y) {
	return __builtin_popcount(x ^ y);
}

int dp(int i, int j) {
	if (j < 0) {
		return -1;
	}
	if (i == n) {
		return (j == 0) ? 1 : -1;
	}
	if (vis[i][j]) {
		return mem[i][j];
	}
	vis[i][j] = true;

	int ans = -1;
	for (int ni = 9; ni >= 0; ni--) {
		if ((num[i] & a[i]) != a[i]) continue;

		int x = num[ni];
		if (dp(i + 1, j - diff(a[i], x)) != -1) {
			ans = ni;
			nxt[i][j] = j - diff(a[i], x);;
			break;
		}
	}

	return mem[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	string bin;
	for (int i = 0; i < n; i++) {
		cin >> bin;
		
		int x = 0;
		for (int i = 0; i < 7; i++) {
			x <<= 1;
			x += (bin[i] == '1') ? 1 : 0;
		}
		a[i] = x;
	}

	if (dp(0, k) == -1) {
		cout << -1 << '\n';
		return  0;
	}

	int j = k;
	for (int i = 0; i < n; i++) {
		cout << dp(i, j);
		j = nxt[i][j];
	}
	cout << '\n';

	return 0;
}
