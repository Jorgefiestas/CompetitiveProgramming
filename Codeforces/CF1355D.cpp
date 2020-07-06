#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, s, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	if (s >= n * 2) {
		cout << "YES\n";
		cout << s - 2 * (n - 1);
		for (int i = 1; i < n; i++) {
			cout << ' ' << 2;
		}
		cout << '\n';
		cout << 1 << '\n';
		return 0;
	}

	cout << "NO\n";
	return 0;
}
