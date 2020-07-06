#include <bits/stdc++.h>
using namespace std;
const int B = 30;
int t, n;

struct Trie {
	Trie* children[2] = {nullptr, nullptr};
	
	void insert(int x, int idx) {
		if (idx == -1) {
			return;
		}

		int c = (x & (1 << idx)) ? 1 : 0;
		if (!children[c]) {
			children[c] = new Trie();
		}
		children[c]->insert(x, idx - 1);
	}

	int query(int x, int idx) {
		if (idx == -1) {
			return 0;
		}

		int c = (x & (1 << idx)) ? 0 : 1;
		if (children[c]) {
			return (1 << idx) | children[c]->query(x, idx - 1);
		}
		if (children[1 - c]) {
			return children[1 - c]->query(x, idx - 1);
		}
		return 0;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		Trie* root = new Trie();
		root->insert(0, B);

		int a, ans = 0, pref = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			pref ^= a;
			ans = max(ans, root->query(pref, B));
			root->insert(pref, B);
		}

		cout << ans << '\n';
	}

	return 0;
}
