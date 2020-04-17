#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, dcnt[N];
int np[N], mu[N], cnt[N];

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
			dcnt[i] += cnt[j];
		}
	}
}

long long c3(int x) {
	return x * 1LL * (x - 1) * (x - 2) / 6;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	sieve();

	long long ans = 0;
	for (int i = 1; i < N; i++) {
		ans += mu[i] * 1LL * c3(dcnt[i]);
	}

	cout << ans << '\n';

	return 0;
}
