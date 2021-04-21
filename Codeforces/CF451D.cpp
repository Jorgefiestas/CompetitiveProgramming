#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int cnt[2][2];
string str, comp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	long long even = 0;
	long long odd = 0;

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		bool p = i % 2;

		cnt[p][c] += 1;
		odd += (long long) cnt[p][c];
		even += (long long) cnt[!p][c];
	}

	cout << even << ' ' << odd << '\n';

	return 0;
}
