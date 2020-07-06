#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int p[N];
string s;

void prefix() {
	int n = s.size();
	for (int i = 1; i < s.size(); i++) {
		int j = p[i - 1];
		while (j != 0 && s[j] != s[i]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	while (cin >> str) {
		string rstr = str;
		reverse(rstr.begin(), rstr.end());

		s = rstr + '#' + str;
		prefix();

		int r = str.size() - p[s.size() - 1] - 1;

		cout << str;
		for (int i = r; i >= 0; i--) {	
			cout << str[i];
		}
		cout << '\n';
	}

	return 0;
}
