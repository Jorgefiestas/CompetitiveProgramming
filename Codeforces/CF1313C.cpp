#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
using pii = pair<int, long long>;
int n;
int nxt[N], prv[N];
long long h[N], lh[N], rh[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	
	stack<pii> st;
	st.push({0, h[0]});
	for (int i = 1; i < n; i++) {
		while (!st.empty() && st.top().second >= h[i]) {
			nxt[st.top().first] = i;
			st.pop();
		}
		st.push({i, h[i]});
	}
	while (!st.empty()) {
		nxt[st.top().first] = n;
		st.pop();
	}
	
	st.push({n - 1, h[n - 1]});
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty() && st.top().second >= h[i]) {
			prv[st.top().first] = i;
			st.pop();
		}
		st.push({i, h[i]});
	}
	while (!st.empty()) {
		prv[st.top().first] = -1;
		st.pop();
	}
	
	for (int i = 0; i < n; i++) {
		lh[i] = (i - prv[i]) * h[i];
		if (prv[i] != -1) lh[i] += lh[prv[i]];
	}
	for (int i = n - 1; i >= 0; i--) {
		rh[i] = (nxt[i] - i) * h[i] + rh[nxt[i]];
	}
	
	long long ans = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		long long tans = lh[i] - h[i] + rh[i];
		if (tans > ans) {
			ans = tans;
			idx = i;
		}
	}

	for (int i = idx - 1; i >= 0; i--) {
		h[i] = min(h[i], h[i + 1]);
	}
	for (int i = idx + 1; i < n; i++) {
		h[i] = min(h[i], h[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		cout << h[i] << ' ';
	}
	cout << endl;

	return 0;
}
