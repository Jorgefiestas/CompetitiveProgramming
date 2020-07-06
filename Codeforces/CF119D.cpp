#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 100;
int n, p[N], z[N];
string a, b;

int impossible() {
	cout << -1 << ' ' << -1 << '\n';
	return 0;
}

void zeta(const string &str) {
	int l = 0, r = 0;
	for (int i = 1; i < str.size(); i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

void prefix(const string &str) {
	for (int i = 1; i < str.size(); i++) {
		int j = p[i - 1];
		while (j > 0 && str[i] != str[j]) {
			j = p[j - 1];
		}
		if (str[i] == str[j]) {
			j++;
		}
		p[i] = j;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, a);
	getline(cin, b);
	if (a.size() != b.size()) {
		return impossible();
	}

	n = a.size();

	string s1 = b + '\1' + a;
	zeta(s1);

	string s2 = a;
	reverse(s2.begin(), s2.end());
	s2 = s2 + '\1' + b;
	prefix(s2);

	int ai = -1;
	int aj = -1;

	int i = 0;
	while (i < n - 1 && a[i] == b[n - i - 1]) {
		int cj = max(n - p[2 * n - i - 1], i + 1);
		int mbl = i + z[n + i + 2];

		if (mbl >= cj - 1) {
			ai = i;
			aj = cj;
		}

		i++;
	}

	cout << ai << ' ' << aj << '\n';

	return 0;
}
