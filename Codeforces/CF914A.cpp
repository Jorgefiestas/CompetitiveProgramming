#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<int> squares;
	for (int i = -1e3; i <= 1e3; i++) {
		squares.insert(i * i);
	}

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (squares.count(a[i])) continue;
		cout << a[i] << '\n';
		break;
	}

	return 0;
}
