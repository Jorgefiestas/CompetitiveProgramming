#include <bits/stdc++.h>
using namespace std;
const int A = 5e6;
const int N = 5e5;
int n, b[N], a[N], spf[A], pindex[A];
map<int, stack<int>> indices;
vector<int> primes;

void sieve() { 
	for (int x = 2; x < A; x++) {
		spf[x] = x;
	}

	for (int i = 2; i < A; i++) {
		if (spf[i] != i) continue;
		for (int j = i; j < A; j += i) {
			spf[j] = min(spf[j], i);
		}
	}

	for (int x = 2; x < A; x++) {
		if (spf[x] != x) continue;
		primes.emplace_back(x);
		pindex[x] = primes.size();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		cin >> b[i];
	}

	sort(b, b + 2 * n, greater<int>());

	for (int i = 0; i < 2 * n; i++) {
		indices[b[i]].push(i);
	}

	int ai = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (b[i] == -1) continue;

		int x = b[i];
		int pr;

		if (x == spf[x]) {
			pr = pindex[x];
			a[ai] = pr;
		}
		else {
			pr = x / spf[x];
			a[ai] = x;
		}

		b[indices[pr].top()] = -1;
		indices[pr].pop();

		ai += 1;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
