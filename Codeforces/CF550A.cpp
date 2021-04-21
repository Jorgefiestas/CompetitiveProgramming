#include <bits/stdc++.h>
using namespace std;
int n;
string a;
set<int> ba, ab;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;
	n = a.size();

	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 'A' && a[i + 1] == 'B') {
			ab.insert(i);
		}
		if (a[i] == 'B' && a[i + 1] == 'A') {
			ba.insert(i);
		}
	}

	if (ab.empty() || ba.empty()) {
		cout << "NO\n";
		return 0;
	}

	bool pos = false;
	if (*ab.begin() + 1 < *prev(ba.end())) {
		pos = true;
	}
	if (*ba.begin() + 1 < *prev(ab.end())) {
		pos = true;
	}

	if (pos) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
