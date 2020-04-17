#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, seen[N];
vector<int> divisors[N];

void sieve() {
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

	cin >> n;

	int xi, yi;
	for (int i = 1; i <= n; i++) {
		cin >> xi >> yi;

		int cnt = 0;
		for (int d : divisors[xi]) {
			if (seen[d] < i - yi) {
				cnt++;
			}
			seen[d] = i;
		}

		cout << cnt << '\n';
	}

	return 0;
}
