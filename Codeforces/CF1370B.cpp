#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> even, odd;

void solve() {
	cin >> n;
	
	int a;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a;
		if (a % 2) {
			odd.emplace_back(i);
		}
		else {
			even.emplace_back(i);
		}
	}
	
	if (odd.size() % 2) {
		odd.pop_back();
		even.pop_back();
	}
	else {
		if (!odd.empty()) {
			odd.pop_back();
			odd.pop_back();
		}
		else {
			even.pop_back();
			even.pop_back();
		}
	}

	while (!odd.empty()) {
		cout << odd.back() << ' ';
		odd.pop_back();
		cout << odd.back() << '\n';
		odd.pop_back();
	}

	while (!even.empty()) {
		cout << even.back() << ' ';
		even.pop_back();
		cout << even.back() << '\n';
		even.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		even.clear();
		odd.clear();
		solve();
	}

	return 0;
}
