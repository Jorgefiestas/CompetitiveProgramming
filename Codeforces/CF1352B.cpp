#include <bits/stdc++.h>
using namespace std;
int t, n, k;
vector<int> ans;

bool solve() {
	if (n < k) {
		return false;
	}

	if (n % 2) {
		if (k % 2 == 0) {
			return false;
		}

		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) {
			cout << "1 ";
			n--;
		}
		cout << n << '\n';;
		return true;
	}

	if (k % 2) {
		if (n < 2 * k) {
			return false;
		}

		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) {
			cout << "2 ";
			n -= 2;
		}
		cout << n << '\n';

		return true;
	}

	cout << "YES\n";
	for (int i = 0; i < k - 1; i++) {
		cout << "1 ";
		n--;
	}
	cout << n << '\n';

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		ans.clear();

		if (!solve()) {
			cout << "NO\n";
		}
	}

	return 0;
}
