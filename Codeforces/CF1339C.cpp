#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
long long a[N];
long long p2[70];

int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	long long mx = a[0];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int d = mx - a[i];
		if (a[i] > mx) {
			mx = a[i];
		}
		else {
			int tcnt = 0;
			while (d) {
				tcnt++;
				d >>= 1;
			}
			cnt = max(tcnt, cnt);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	return 0;
}
