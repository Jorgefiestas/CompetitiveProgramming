#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, r;

struct Task {
	int a, b;

	bool operator<(const Task &t) const {
		if (b >= 0 && t.b >= 0) {
			if (a == t.a) {
				return b > t.b;
			}
			return a < t.a;
		}
		if (b >= 0) {
			return true;
		}
		if (t.b >= 0) {
			return false;
		}

		return max(a, -b) + b > max(t.a, -t.b) + t.b;
	}
};

Task t[N];

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);

	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		cin >> t[i].a >> t[i].b;
	}

	sort(t, t + n);

	bool poss = true;
	for (int i = 0; i < n; i++) {
		if (r < t[i].a) {
			poss = false;
			break;
		}
		r += t[i].b;
	}

	if (r >= 0 && poss) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
