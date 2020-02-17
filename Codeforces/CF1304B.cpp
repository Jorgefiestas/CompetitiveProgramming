#include <bits/stdc++.h>
using namespace std;
int n, m;
string str[105];
vector<string> frnt, bck;
bool vis[105];

bool is_palindrome(const string &s) {
	for (int i = 0; i < m / 2; i++) {
		if (s[i] != s[m - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (vis[i]) continue;

		for (int j = i + 1; j < n; j++) {
			bool eq = true;
			for (int k = 0; k < m; k++) {
				if (str[i][k] != str[j][m - 1 - k]) {
					eq = false;
					break;
				}
			}
			if (eq) {
				vis[i] = true;
				vis[j] = true;
				frnt.emplace_back(str[i]);
				bck.emplace_back(str[j]);
				break;
			}
		}
	}

	int N = frnt.size() * 2;

	string pal;
	bool pal_exists = false;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		if (is_palindrome(str[i])) {
			pal = str[i];
			pal_exists = true;
			N++;
			break;
		}
	}

	cout << m * N << '\n';

	for  (int i = frnt.size() - 1; i >= 0; i--) {
		cout << frnt[i];
	}
	if (pal_exists) {
		cout << pal;
	}
	for  (string x : bck) {
		cout << x;
	}
	cout << '\n';

	return 0;
}
