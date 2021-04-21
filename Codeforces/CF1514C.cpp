#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
bool seen[N];

int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int inv(int a) {
	int x, y;
	int g = gcd(a, n, x, y);

	if (g != 1)
		return 0;

	if (x >= 0) 
		return x % n;
	return n + x % n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> ans;
	vector<int> dup;

	ans.push_back(1);
	seen[0] = true;
	seen[1] = true;

	for (int x = 2; x < n; x++) {
		if (seen[x]) continue;

		int xp = inv(x);

		if (xp == 0) continue;
		if (x == xp) {
			dup.push_back(x);
			continue;
		}

		seen[x] = true;
		seen[xp] = true;
		ans.push_back(x);
		ans.push_back(xp);
	}

	if (dup.size() > 2) {
		for (int x : dup) {
			ans.push_back(x);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}
