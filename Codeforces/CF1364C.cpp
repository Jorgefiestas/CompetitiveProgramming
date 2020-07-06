#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, a[N], b[N];

int impossible() {
	cout << -1 << '\n';
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mex = 0;
	queue<int> free;
	for (int i = 0; i < n; i++) {
		if (a[i] == mex) {
			free.push(i);
			continue;
		}
		if (a[i] == mex + 1) {
			b[i] = mex;
			mex++;
			continue;
		}

		if (free.size() + 1 < a[i] - mex) {
			cout << i << endl;
			return impossible();
		}

		b[i] = mex;
		for (int j = a[i] - 1; j > mex; j--) {
			b[free.front()] = j;
			free.pop();
		}
		mex = a[i];
	}

	while (!free.empty()) {
		b[free.front()] = 1e6;
		free.pop();
	}


	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';

	return 0;
}
