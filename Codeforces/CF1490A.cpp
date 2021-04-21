#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, n, a[N];

int count(int x, int y) {
	if (x > y) 
		swap(x, y);

	int cnt = 0;
	while (2 * x < y) {
		x += x;
		cnt += 1;
	}
	return cnt;
}

int solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += count(a[i], a[i - 1]);
	}

	return ans;
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
