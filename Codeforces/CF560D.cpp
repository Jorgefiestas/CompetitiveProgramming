#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;

string smallest(string &str, int l, int r) {
	if ((r - l + 1) % 2) {
		return str.substr(l, r - l + 1);
	}
	int m = (l + r) / 2;
	string sa = smallest(str, l, m);
	string sb = smallest(str, m + 1, r);
	return min(sa + sb, sb + sa);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	n = a.size();

	string sa = smallest(a, 0, n - 1);
	string sb = smallest(b, 0, n - 1);

	if (sa == sb) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
