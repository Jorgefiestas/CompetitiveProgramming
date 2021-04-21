#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 998244353;
int dp[N][N][2], dif[2][N];
string x, y;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;
	x = '$' + x;
	y = '$' + y;
	
	int ans = 0;

	for (int i = 1; i < x.size(); i++) {
		for (int j = i; j > 1 && x[j] != x[j - 1]; j--) {
			dif[0][i]++;
		}
		dif[0][i]++;
	}

	for (int i = 1; i < y.size(); i++) {
		for (int j = i; j > 1 && y[j] != y[j - 1]; j--) {
			dif[1][i]++;
		}
		dif[1][i]++;
	}

	for (int i = 1; i < x.size(); i++) {
		for (int j = 1; j < y.size(); j++) {
			if (x[i - 1] != x[i])
				dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][0]);
			if (y[j] != x[i])
				dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][1]);
			if (y[j] != x[i])
				dp[i][j][0] = add(dp[i][j][0], dif[1][j]);


			if (y[j - 1] != y[j])
				dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][1]);
			if (y[j] != x[i])
				dp[i][j][1] = add(dp[i][j][1], dp[i][j - 1][0]);
			if (y[j] != x[i]) 
				dp[i][j][1] = add(dp[i][j][1], dif[0][i]);

			ans = add(ans, dp[i][j][0]);
			ans = add(ans, dp[i][j][1]);
		}
	}

	cout << ans << '\n';

	return 0;
}
