#include <bits/stdc++.h>
using namespace std;
long long n, fac[100][15];
int t, cnt[100][15];

void fact() {
	int j = 0;

	if ((n & 1) == 0) {
		fac[t][j] = 2;
		while ((n & 1) == 0) {
			n >>= 1;
			cnt[t][j]++;
		}
		j++;
	}

	for (long long i = 3; i * i <= n; i += 2) {
		if (n % i) continue;
		fac[t][j] = i;
		while (n % i == 0) {
			n /= i;
			cnt[t][j]++;
		}
		j++;
	}

	if (n > 2) {
		fac[t][j] = n;
		cnt[t][j]++;
		j++;
	}

	for (int i = 0; i < j; i++) {
		cout << fac[t][i] << '^' << cnt[t][i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		fact();
		t++;
	}
	return 0;
}
