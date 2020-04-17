#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, mu[N], f[N], p2[N], cnt[N];
bool np[N];
vector<int> divisors[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

void sieve() {
	for (int i = 1; i < N; i++) {
		mu[i] = 1;
	}

	for (int i = 2; i * i < N; i++) {
		if (np[i]) continue;
		for (int j = i; j < N; j += i) {
			np[j] = true;
			mu[j] *= -i;
		}
		for (int j = i * i; j < N; j += i * i) {
			mu[j] = 0;
		}
	}
	for (int i = 2; i <= N; i++) {
        if (mu[i] == i) {
            mu[i] = 1;
		}
        else if (mu[i] == -i) {
            mu[i] = -1;
		}
        else if (mu[i] < 0) {
            mu[i] = 1;
		}
        else if (mu[i] > 0) {
            mu[i] = -1;
		}
    }

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divisors[j].emplace_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	mu[1] = 0;

	cin >> n;

	p2[0] = 1;
	for (int i = 0; i <= n + 1; i++) {
		p2[i + 1] = add(p2[i], p2[i]);
	}

	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int d : divisors[a]) {
			cnt[d]++;
		}
	}

	for (int i = 2; i < N; i++) {
		f[i] = sub(p2[cnt[i]], 1);
	}

	int ans = sub(p2[n], 1);
	for (int i = 2; i < N; i++) {
		if (mu[i] < 0) {
			ans = sub(ans, f[i]);
		}
		else if (mu[i] > 0) {
			ans = add(ans, f[i]);
		}
	}

	cout << ans << '\n';

	return 0;
}
