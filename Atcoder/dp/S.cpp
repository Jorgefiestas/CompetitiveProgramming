#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
const long long mod = 1e9 + 7;
int d, n;
string num;
long long mem[N][105][2];
bool vis[N][105][2];

long long dp(int idx, int m, int last) {
	if (idx == n) {
		return (!m) ? 1 : 0;
	}
	if (vis[idx][m][last]) {
		return mem[idx][m][last];
	}
	vis[idx][m][last] = true;

	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		if (last && i == num[idx] - '0') {
			ans = (ans + dp(idx + 1, (m + i) % d, 1)) % mod;
			break;
		}
		ans = (ans + dp(idx + 1, (m + i) % d, 0)) % mod;
	}

	return mem[idx][m][last] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> num >> d;
	n = num.size();

	cout << (mod + dp(0, 0, 1) - 1) % mod << '\n';

	return 0;
}
