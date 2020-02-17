#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
int lsl[200005], lsr[200005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	bool inc = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= a[i - 1]) {
			inc = false;
		}
	}

	if (inc) {
		cout << n << endl;
		return 0;
	}

	int mxlen = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			lsl[i] = lsl[i - 1] + 1;
		}
		else {
			lsl[i] = 1;
		}
		mxlen = max(mxlen, lsl[i]);
	}

	for (int i = n; i > 0; i--) {
		if (a[i] < a[i + 1]) {
			lsr[i] = lsr[i + 1] + 1;
		}
		else {
			lsr[i] = 1;
		}
		mxlen = max(mxlen, lsr[i]);
	}

	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i + 1]) {
			mxlen = max(mxlen, lsl[i - 1] + lsr[i + 1]);
		}
	}

	cout << mxlen << endl;

	return 0;
}
