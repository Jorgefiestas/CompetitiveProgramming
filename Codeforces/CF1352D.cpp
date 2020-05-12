#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int t, n, arr[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int a = arr[0], a_acc = arr[0];
		int b = 0, b_acc = 0;
		int l = 1, r = n - 1;
		int turns = 1;

		while (l <= r) {
			turns++;
			b = 0;
			while (l <= r && b <= a) {
				b += arr[r];
				b_acc += arr[r];
				r--;
			}

			if (l > r) break;
			
			turns++;
			a = 0;
			while (l <= r && a <= b) {
				a += arr[l];
				a_acc += arr[l];
				l++;
			}
		}

		cout << turns << ' ' << a_acc << ' ' << b_acc << '\n';
	}

	return 0;
}
