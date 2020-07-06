#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int L = 20;
int n, cnt[N][L];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void addDiv(int x) {
	int ox = x;
	for (int i = 2; i * i <= x; i++) {
		int j = 1;
		while (x % i == 0) {
			cnt[i][j]++;
			x /= i;
			j++;
		}
	}

	if (x > 1) {
		cnt[x][1]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int x, g = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		addDiv(x);
		if (!g) {
			g = x;
		}
		else {
			g = gcd(x, g);
		}
	}

	long long ans = 1;
	for (int i = 2; i < N; i++) {
		for (int p = 1; p < L; p++) {
			if (cnt[i][p] == n) {
				ans *= (long long) i * i;
			}
			if (cnt[i][p] == n - 1) {
				ans *= (long long) i;
			}
		}
	}

	ans = (long long) ans / g;

	cout << ans << '\n';

	return 0;
}
