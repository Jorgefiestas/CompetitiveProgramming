#include <bits/stdc++.h>
using namespace std;
int t;
long long n;

long long solve() {
	long long ans = 0;
	for (int i = 0; i <= 60; i++) {
		if (!(n & (1LL << i))) continue;
		ans += (1LL << (i + 1)) - 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		cout << solve() << '\n';
	}

	return 0;
}
