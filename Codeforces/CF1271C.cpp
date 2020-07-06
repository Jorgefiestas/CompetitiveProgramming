#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 200000;
const int dx[8] = {0, -1, -1, -1, 0, 1 ,1 ,1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int n;
pii s, points[N + 1];

bool inRec(pii rec, pii p) {
	bool x = min(s.first, rec.first) <= p.first  && p.first <= max(s.first, rec.first);
	bool y = min(s.second, rec.second) <= p.second  && p.second <= max(s.second, rec.second);
	return x && y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s.first >> s.second;
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

	int mxcnt = -1;
	pii ans = {-1, -1};
	for (int i = 0; i < 8; i++) {
		pii pos = {s.first + dx[i], s.second + dy[i]};
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			pii p = points[j];
			if (inRec(p, pos)) cnt++;
		}
		if (cnt > mxcnt) {
			mxcnt = cnt;
			ans = pos;
		}
	}
	
	cout << mxcnt << endl;
	cout << ans.first << ' ' << ans.second << endl;

	return 0;
}
