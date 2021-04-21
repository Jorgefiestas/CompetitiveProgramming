#include <bits/stdc++.h>
using namespace std;
int t, p, f, cs, cw, s, w;

int solve() {
	cin >> p >> f;
	cin >> cs >> cw >> s >> w;

	if (s > w) {
		swap(cs, cw);
		swap(s, w);
	}
	if (p < f) {
		swap(p, f);
	}

	int ans = 0;
	for (int as = 0; as <= cs; as++) {
		if (as * s > p) break;

		int aw = min((p - as * s) / w, cw);

		int bs = min(f / s, cs - as); 
		int bw = min ((f - bs * s) / w, cw - aw);

		ans = max(ans, as + bs + aw + bw);
	}

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
