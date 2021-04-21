#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 10;
int t, c, d, x, cpf[N];

void sieve() {
	for (int i = 2; i < N; i++) {
		if (cpf[i]) continue;
		for (int j = i; j < N; j += i) {
			cpf[j] += 1;
		}
	}

	for (int i = 1; i < N; i++) {
		cpf[i] = 1 << cpf[i];
	}
}

long long calc(int g) {
	int k = x / g + d;
	if (k % c)
		return 0;
	return cpf[k / c];
}

long long solve() {
	cin >> c >> d >> x;

	long long ans = 0;
	for (int g = 1; g * g <= x; g++) {
		if (x % g) continue;

		ans += calc(g);
		if (x / g != g) 
			ans += calc(x / g);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
