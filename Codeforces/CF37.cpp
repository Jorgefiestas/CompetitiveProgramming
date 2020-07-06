#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e3  + 100;
const int N2 = 1e6 + 100;
int n, trie[N2][2];
pii len[N];
bool full[N2];

int nodecnt = 1;
string str, res[N];

void insert(int node, int d) {
	if (d == 0) {
		full[node] = true;
		return;
	}

	if (!trie[node][0]) {
		trie[node][0] = nodecnt++;
		trie[node][1] = nodecnt++;
	}

	int lc = trie[node][0];
	int rc = trie[node][1];

	if (!full[lc]) {
		str += '0';
		insert(lc, d - 1);
	}
	else {
		str += '1';
		insert(rc, d - 1);
	}

	full[node] = full[lc] && full[rc];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int l;
	for (int i = 0; i < n; i++) {
		cin >> l;
		len[i] = {l, i};
	}

	sort(len, len + n);

	for (int i = 0; i < n; i++) {
		if (full[0]) {
			cout << "NO\n";
			return 0;
		}

		str.clear();
		insert(0, len[i].first);
		res[len[i].second] = str;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}
