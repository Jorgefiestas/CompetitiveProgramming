#include <bits/stdc++.h>
using namespace std;
int n;
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	n = str.size();

	long long ans = 0;
	for (char a = 'a';  a <= 'z'; a++) {
		for (char b = 'a'; b <= 'z'; b++) {
			int cnt = 0;
			long long can = 0;

			for (int i = 0; i < n; i++) {
				if (str[i] == b) {
					can += (long long) cnt;
				}
				if (str[i] == a) {
					cnt += 1;
				}
			}

			can = max(can, (long long) cnt);
			ans = max(ans, can);
		}
	}

	cout << ans << '\n';

	return 0;
}
