#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a, b;
string key;
bool possa[N], possb[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> key;
	cin >> a >> b;

	n = key.size();

	int m = 0;
	for (int i = 0; i < n; i++) {
		int d = key[i] - '0';
		m = (m * 10 + d) % a;

		if (!m) {
			possa[i] = true;
		}
	}

	m = 0;
	int offset = 1;
	for (int i = n - 1; i >= 0; i--) {
		int d = key[i] - '0';
		m = (m + d * offset) % b;
		offset = (offset * 10) % b;

		if (d && !m) {
			possb[i] = true;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (!possa[i] || !possb[i + 1]) continue;
		
		cout << "YES\n";
		for (int j = 0; j <= i; j++) {
			cout << key[j];
		}
		cout << '\n';
		for (int j = i + 1; j < n; j++) {
			cout << key[j];
		}
		cout << '\n';

		return 0;
	}
	
	cout << "NO\n";

	return 0;
}
