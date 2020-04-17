#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q, n, r, a[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	cin >> q;

	while (q--) {
		cin >> n >> r;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n, greater<int>());

		int cnt = 0;
		int push = 0;
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] <= push) break;
			if (a[i] == last) continue;
			cnt++;
			push += r;
			last = a[i];
		}

		cout << cnt << '\n';
	}

	return 0;
}
