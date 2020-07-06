#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int A = 1e7 + 5;
const int N = 5e5 + 100;
int n, spf[A];
int d0[N], d1[N];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void sieve() {
	for (int i = 2; i < A; i++) {
		spf[i] = i;
	}

	for (int i = 2; i * i < A; i++) {
		if (spf[i] != i) continue;
		for (int j = i * i; j < A; j += i) {
			spf[j] = min(spf[j], i);
		}
	}
}

pii query(int x) {
	int sf = spf[x];
	while (x % sf == 0) {
		x /= sf;
	}
	if (x == 1) {
		return {-1, -1};
	}

	return {sf, x};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pii ans = query(a);
		d0[i] = ans.first;
		d1[i] = ans.second;
	}

	for (int i = 0; i < n; i++) {
		cout << d0[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << d1[i] << ' ';
	}
	cout << '\n';

	return 0;
}
