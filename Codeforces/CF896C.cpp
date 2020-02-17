#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 19) + 2;
const long long mod = 1e9 + 7;
int n, cnt[75];
int spf[75], pidx[70];
int mem[72][N], mask[72];

void sieve() {
	for (int i = 2; i <= 70; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i <= 70; i++) {
		if (spf[i] != i) continue;

		for (int j = i * i; j <= 70; j += i) {
			spf[j] = min(spf[j],  i);
		}
	}

	int p = 0;
	for (int i =2; i <= 70; i++) {
		if (spf[i] == i) {
			pidx[i] = p++;
		}
	}
}

int to_bit(int x) {
	int bit = 0;
	while (x > 1) {
		bit ^= (1 << pidx[spf[x]]);
		x /= spf[x];
	}
	return bit;
}

long long exp(long long x, int y) {
	if (y < 0) {
		return 0;
	}

	long long ans = 1;
	while (y) {
		if (y & 1) {
			ans = (ans * x) % mod;
		}
		y >>= 1;
		x = (x * x) % mod;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();
	for (int i = 1; i <= 70; i++) {
		mask[i] = to_bit(i);
	}

	cin >> n;
	
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}

	mem[0][0] = 1;
	for (int i = 1; i <= 70; i++) {
		long long  cntInc = exp(2, cnt[i] - 1);
		long long  cntExc = max(1LL, exp(2, cnt[i] - 1));
		for (int j = 0; j < N; j++) {
			mem[i][j] = (1LL *  mem[i - 1][j] * cntExc) % mod;
			mem[i][j] = (mem[i][j] + (1LL * mem[i - 1][j ^ mask[i]] * cntInc) % mod) % mod;
		}
	}

	cout << mem[70][0] - 1 << '\n';
}
