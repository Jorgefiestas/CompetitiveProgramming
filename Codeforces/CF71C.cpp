#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n;
bool mood[N];

bool check(int m) {
	if (n / m < 3) {
		return false;
	}

	for (int k = 0; k < m; k++) {
		bool g = true;
		for (int i = k; i < n; i += m) {
			g = g && mood[i];
		}
		if (g) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mood[i];
	}

	for (int i = 1; i * i <= n; i++) {
		if (n % i) continue;
		if (check(i) || check(n / i)) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}
