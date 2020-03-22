#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
unordered_map<int, long long> cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		cnt[b - i] += (long long) b;

	}

	long long ans = 0;

	for (auto p : cnt) {
		ans = max(ans, p.second);
	}

	cout << ans << endl;

	return 0;
}
