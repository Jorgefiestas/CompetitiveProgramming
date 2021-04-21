#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, n, a[N];
 
int count(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		if (i == 1 || i == n) continue;

		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			ans += 1;
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			ans += 1;
	}
	return ans;
}
 
int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	int ans = count(1, n);
 
	int sub = 0;
	for (int i = 2; i < n; i++) {
		int org = count(i - 1, i + 1);
		int pv = a[i];

		a[i] = a[i - 1];
		int can1 = org - count(i - 1, i + 1);

		a[i] = a[i + 1];
		int can2 = org - count(i - 1, i + 1);

		sub = max({sub, can1, can2});
		
		a[i] = pv;
	}
 
	return ans - sub;
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
