#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1005;
int w, b;
ld dp[N][N][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> b;

	for (int i = 0; i <= w; i++) {
		for (int j = i ? 0 : 1; j <= b; j++) {
			ld pw = (ld) i / (i + j);
			ld pb = (ld) j / (i + j);
			dp[i][j][1] = pw;
			dp[i][j][1] += pb * dp[i][j - 1][0];
			
			if (i + j > 1) {
				ld pbb = (ld) pb * (j - 1.0) / (i + j - 1);
				ld pbw = (ld) pb * i / (i + j - 1);

				if (j > 1) {
					dp[i][j][0] = pbb * dp[i][j - 2][1];
				}
				if (i && j) {
					dp[i][j][0] += pbw * dp[i - 1][j - 1][1];
				}
			}
		}
	}
	
	cout << setprecision(15) << dp[w][b][1] << '\n';
}
