#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int triecnt = 1;

struct Node {
	bool state = false;
	bool state2 = false;
	Node* to[26];

	Node() {
		memset(to, 0, sizeof to);
	}

	void insert(string &str, int idx) {
		if (idx == str.size()) {
			state2 = true;
			return;
		}
		
		int c = str[idx] - 'a';
		if (!to[c]) {
			to[c] = new Node();
		}
		to[c] -> insert(str, idx + 1); 
	}

	void calc_state() {
		for (int i = 0; i < 26; i++) {
			if (!to[i]) continue;
			to[i] -> calc_state();
			state = state || !to[i] -> state;
		}
	}

	void calc_state2() {
		for (int i = 0; i < 26; i++) {
			if (!to[i]) continue;
			to[i] -> calc_state2();
			state2 = state2 || !to[i] -> state2;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	Node root;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		root.insert(str, 0);
	}

	root.calc_state();
	if (!root.state) {
		cout << "Second\n";
		return 0;
	}

	root.calc_state2();
	if (root.state && root.state2) {
		cout << "First\n";
		return 0;
	}

	if (k % 2) {
		cout << "First\n";
	}
	else {
		cout <<  "Second\n";
	}

	return 0;
}
