#include <bits/stdc++.h>
using namespace std;
const int N = 40005;
int t, a, b, ab, q, cnt;
int good[N];

long long query(long long n) {
	long long tc = n / (1LL * ab);
	long long rem = n % (1LL * ab);
	return tc * 1LL * cnt + 1LL * good[rem];
}

void solve() {
	cin >> a >> b >> q;
	ab = a * b;

	good[0] = 0;
	for (int i = 1; i <= a * b; i++) {
		good[i] = good[i - 1];
		if ((i % a) % b != (i % b) % a) {
			good[i] += 1;
			cnt++;
		}
	}

	long long li, ri;
	for (int i = 0; i < q; i++) {
		cin >> li >> ri;
		cout << query(ri) - query(li - 1) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cnt = 0;
		solve();
	}

	return 0;
}
