#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	cin >> n;

	int neg = 1;
	int pos = -1;
	set<int> ze;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		
		if (x == 0) {
			ze.insert(x);
		}
		else if (x < 0) {
			if (neg != 1) {
				ze.insert(x);
			}
			else {
				neg = x;
			}
		}
		else if (x > 0) {
			if (pos != -1) {
				ze.insert(x);
			}
			else {
				pos = x;
			}
		}
	}

	cout << 1 << ' ' << neg << '\n';

	if (pos == -1) {
		cout << 2 << ' ';
		cout << *ze.begin() << ' ';
		ze.erase(ze.begin());
		cout << *ze.begin() << '\n';
		ze.erase(ze.begin());
	}
	else {
		cout << 1 << ' ' << pos << '\n';
	}

	cout << ze.size();
	for (int a : ze) {
		cout << ' ' << a;
	}
	cout << '\n';

	return 0;
}
