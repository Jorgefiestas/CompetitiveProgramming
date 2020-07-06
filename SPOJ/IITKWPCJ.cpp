#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;

bool solve() {
	if (a.size() > b.size()) {
		swap(a, b);
	}

	for (int i = 0; i < b.size(); i++) {
		if (a[i % a.size()] != b[i]) {
			return false;
		}
	}

	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i] || a[i] != b[b.size() - a.size() + i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
