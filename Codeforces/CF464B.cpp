#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int xyz[8][3];
unordered_set<long long> st;

#define N 20000001
#define N2 4000004000001

bool is_cube(int idx) {
	if (idx == 8) {
		long long s = LLONG_MAX;

		for (int a = 0; a < 2; a++) {
			unordered_map<long long, int> cnt;

			for (int b = 0; b < 8; b++) {
				if (a == b) continue;

				long long d = 0;
				for (int i = 0; i < 3; i++) {
					d += 1LL * (xyz[a][i] - xyz[b][i]) * (xyz[a][i] - xyz[b][i]);
				}
				++cnt[d];
				s = min(s, d);
			}

			if (cnt[s] != 3 || cnt[2 * s] != 3 || cnt[3 * s] != 1) {
				return false;
			}
		}
		return true;
	}

	sort(xyz[idx], xyz[idx] + 3);
	do {
		long long tp = 1LL * xyz[idx][0] + 1LL * xyz[idx][1] * N + 1LL * xyz[idx][2] * N2;
		if (st.count(tp)) {
			continue;
		}
				
		st.insert(tp);
		if (is_cube(idx + 1)) {
			return true;
		}
		st.erase(tp);
	} while (next_permutation(xyz[idx], xyz[idx] + 3));

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		cin >> xyz[i][0];
		cin >> xyz[i][1];
		cin >> xyz[i][2];

		xyz[i][0] += 1e6;
		xyz[i][1] += 1e6;
		xyz[i][2] += 1e6;
	}

	
	long long tp = 1LL * xyz[0][0] + 1LL * xyz[0][1] * N + 1LL * xyz[0][2] * N2;
	st.insert(tp);

	if (is_cube(1)) {
		cout << "YES" << '\n';
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				cout << xyz[i][j] - 1000000 << ' ';
			}
			cout << '\n';
		}
	}

	else {
		cout << "NO"  << '\n';
	}

	return 0;
}
