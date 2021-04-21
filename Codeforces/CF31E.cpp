#include <bits/stdc++.h>
using namespace std;
const int N = 19;
int n, tran[2 * N][N];
long long num[2 * N], p10[N];
long long dp[2 * N][N];
string snum;

void print(int i, int j) {
	if (i == 0) return;
	print(i - 1, tran[i][j]);
	char c = (j == tran[i][j]) ? 'M' : 'H';
	cout << c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> snum;

	for (int i = 1; i <= 2 * n; i++) {
		num[i] = snum[i - 1] - '0';
	}

	p10[0] = 1;
	for (int i = 1; i <= 18; i++) {
		p10[i] = 10LL * p10[i - 1];
	}

	for (int i = 1; i <= 2 * n; i++) {
		for (int j = max(0, i - n); j <= min(i, n); j++) {
			int k = i - j;

			if (j > 0) {
				dp[i][j] = dp[i - 1][j - 1] + num[i] * p10[n - j];
				tran[i][j] = j - 1;
			}
			if (k > 0) {
				long long tmp = dp[i - 1][j] + num[i] * p10[n - k];

				if (tmp >= dp[i][j]) {
					tran[i][j] = j;
					dp[i][j] = tmp;
				}
			}
		}
	}
	
	print(2 * n, n);
	cout << '\n';

	return 0;
}
