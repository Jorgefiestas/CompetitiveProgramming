#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, a[N];

int calc() {
	int d = a[1] - a[0];

	int cnt = 0;
	int last = a[1];

	for (int i = 2; i < n; i++) {
		if (abs(a[i] - last - d) >= 2) {
			return -1;
		}
		cnt += (a[i] != last + d) ? 1 : 0;
		last = last + d;
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n <= 2) {
		cout << 0 << '\n';
		return 0;
	}

	int f = a[0];
	int s = a[1];
	int ans = INT_MAX;

	for (int i = -1; i <= 1; i++) {

		for (int j = -1; j <= 1; j++) {
			a[0] = f + i;
			a[1] = s + j;

			int can = calc();
			if (can == -1) continue;

			can += i ? 1 : 0;
			can += j ? 1 : 0;

			ans = min(ans, can);
		}
		a[0] += 1;
	}

	if (ans == INT_MAX) {
		ans = -1;
	}

	cout << ans << '\n';

	return 0;
}
