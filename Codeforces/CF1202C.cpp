#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, xmov[N], ymov[N];
string ins;

int dif(int arr[N], int tar, int d) {
	int s;
	for (int i = 0; i < n; i++) {
		if (arr[i] != tar) continue;
		s = i;
		break;
	}

	int mn = 0, mx = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (i == s) {
			k += d;
			if (i) {
				mn = min(mn, arr[i - 1] + k);
				mx = max(mx, arr[i - 1] + k);
			}
			else {
				mn = min(mn, k);
				mx = max(mx, k);
			}
		}

		mn = min(mn, arr[i] + k);
		mx = max(mx, arr[i] + k);

	}

	return mx - mn + 1;
}

long long solve() {
	cin >> ins;
	n = ins.size() + 1;

	int x = 0;
	int y = 0;

	int mnx = 0, mxx = 0;
	int mny = 0, mxy = 0;


	int i = 1;
	for (char c : ins) {
		switch(c) {
			case 'W':
				y++;
				break;
			case 'A':
				x--;
				break;
			case 'S':
				y--;
				break;
			case 'D':
				x++;
				break;
		}

		xmov[i] = x;
		ymov[i] = y;
		i++;

		mnx = min(x, mnx);
		mny = min(y, mny);
		mxx = max(x, mxx);
		mxy = max(y, mxy);
	}

	long long ans = LLONG_MAX;

	int dx = dif(xmov, mxx, -1);
	dx = min(dx, dif(xmov, mnx, 1));

	ans = min(ans, (long long) dx * (mxy - mny + 1));

	int dy = dif(ymov, mxy, -1);
	dy = min(dy, dif(ymov, mny, 1));

	ans = min(ans, (long long) dy * (mxx - mnx + 1));

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	
	return 0;
}
