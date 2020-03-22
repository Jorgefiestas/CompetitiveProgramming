#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, oa, ob, oc;
vector<int> substs(7);

int main() {
	cin >> t;

	for (int i = 1; i <= 7; i++) {
		substs[i - 1] = i;
	}

	while (t--) {
		cin >> oa >> ob >> oc;

		int ans = 0;

		sort(substs.begin(), substs.end());
		do {
			a = oa;
			b = ob;
			c = oc;
			int cnt = 0;
			for (int i : substs) {
				bool pos = true;

				if (i & (1 << 0) && !a){
					pos = false;
				}
				if (i & (1 << 1) && !b){
					pos = false;
				}
				if (i & (1 << 2) && !c){
					pos = false;
				}

				if (!pos) continue;

				cnt++;

				if (i & (1 << 0)){
					a--;
				}
				if (i & (1 << 1)){
					b--;
				}
				if (i & (1 << 2)){
					c--;
				}
			}
			ans = max(ans, cnt);
		} while (next_permutation(substs.begin(), substs.end()));

		cout << ans << '\n';
	}

	return 0;
}
