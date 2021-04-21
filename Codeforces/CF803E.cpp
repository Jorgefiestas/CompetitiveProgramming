#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, k;
string str;
bool dp[N][2 * N];
char tran[N][2 * N];
map<char, int> conv;

void trace(int i, int j) {
	if (i == 0) return;
	char c = tran[i][j];
	trace(i - 1, j - conv[c]);
	cout << tran[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	conv['W'] = 1;
	conv['L'] = -1;
	conv['D'] = 0;

	cin >> n >> k >> str;

	dp[0][k] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 2 * k; j++) {
			if (!dp[i][j]) continue;
			char c = str[i];

			if (c != '?') {
				dp[i + 1][j + conv[c]] = true;
				tran[i + 1][j + conv[c]] = c;
				continue;
			}
			else {
				dp[i + 1][j + 1] = true;
				tran[i + 1][j + 1] = 'W';

				dp[i + 1][j] = true;
				tran[i + 1][j] = 'D';

				dp[i + 1][j - 1] = true;
				tran[i + 1][j - 1] = 'L';
			}
		}
	}

	if (dp[n][2 * k]) {
		trace(n, 2 * k);
		cout << '\n';
	}
	else if (dp[n][0]) {
		trace(n, 0);
		cout << '\n';
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
