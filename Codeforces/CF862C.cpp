#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int L = 18;
int n, x;
bool par[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	if (n == 2 && x == 0) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	if (n == 1) {
		cout << x << '\n';
		return 0;
	}
	if (n == 2) {
		cout  << 0 << ' ' << x << '\n';
		return 0;
	}

	vector<int> ans;

	int y = 0;
	for (int i = 1; i <= n - 3; i++) {
		y = y ^ i;
		ans.emplace_back(i);
	}

	ans.push_back(x ^ (1 << 18));
	ans.push_back(y ^ (1 << 17));
	ans.push_back(3 << 17);

	for (int a : ans) {
		cout << a << ' ';
	}
	cout << '\n';

	return 0;
}
