#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
set<int> a;

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		a.insert(ai);
	}

	int ans = 1;
	int lst = 0;
	for (int h : a) {
		ans = mul(ans, h - lst + 1);
		lst = h;
	}

	cout << ans << '\n';

	return 0;
}
