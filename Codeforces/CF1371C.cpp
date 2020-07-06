#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, n, m;

bool solve() {
	cin >> a >> b >> n >> m;
	if (a > b) {
		swap(a, b);
	}

	return !(a + b < n + m || a < m);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		if (solve()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
