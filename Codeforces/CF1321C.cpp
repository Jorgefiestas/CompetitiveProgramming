#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int n;
string str;

bool check(int i) {
	return (i > 0 && str[i] == str[i - 1] + 1) || (i < n - 1 && str[i] == str[i + 1] + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str;

	int cnt = 0;
	for (char c = 'z'; c >= 'a'; c--) {
		for (int i = 0; i < n; i++) {
			if (c == str[i] && check(i)) {
				string nstr;
				for (int j = 0; j < n; j++) {
					if (j == i) continue;
					nstr += str[j];
				}
				str = nstr;
				c++;
				cnt++;
				n--;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
