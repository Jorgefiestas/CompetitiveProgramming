#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int P = 1e7 + 5;
int t, n;
unordered_set<int> divisors;
vector<int> primes;
int spf[P];

void sieve() {

	for (int i = 1; i <= P; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < P; i++) {
		if(spf[i] != i) continue;
		for (int j = i * i; j <= P; j += i) {
			spf[j] = min(spf[j], i);
		}
	}

	for (int i = 2; i <= P; i++) {
		if (spf[i] == i) {
			primes.emplace_back(i);
		}
	}
}

void get_div(long long x) {
	while(x > 1) {
		divisors.insert(spf[x]);
		x /= spf[x];
	}
}

int solve() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		get_div(a);
	}

	for (int p : primes) {
		if (divisors.count(p)) continue;
		return p;
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> t;

	while (t--) {
		divisors.clear();
		cout << solve() << '\n';
	}

	return 0;
}
