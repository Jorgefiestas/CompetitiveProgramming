#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t, p[N];
string str;

void prefix() {
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

	cin >> t;
	while (t--) {
		cin >> str;
		prefix();

		int l = 0;
		for (int i = 0; i < str.size(); i++) {
			if (p[i] - 1 >= i - p[i] + 1) continue;
			l = max(l, p[i]);
		}
		int s = str.size() - 2 * l;
		for (int i = 0; i < 8; i++) {
			cout << str[(s + i) % l];
		}
		cout << "...\n";
	}

	return 0;
}
