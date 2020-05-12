#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t, nodecnt;
int mem[N][5005];
bool vis[N][1005];

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int nballs = 0;
	int ntwigs = 0;
	int id;

	Node() {
		id = nodecnt++;

		char c;
		while (cin >> c, c != ')') {
			if (c == '(') {
				if (!left) {
					left = new Node();
					nballs += left->nballs;
					ntwigs += left->ntwigs;
				}
				else {
					right = new Node();
					nballs += right->nballs;
					ntwigs += right->ntwigs;
				}
			}
			else {
				nballs = 1;
			}
		}

		if (!left) {
			ntwigs = 1;
		}
	}
};

int dp(Node *node, int n) {
	if (node->ntwigs < n) {
		return 10000;
	}
	if (vis[node->id][n]) {
		return mem[node->id][n];
	}
	vis[node->id][n] = true;
	int ans = 0;

	if (!(node->left)) {
		ans = (n != node->nballs) ? 1 : 0;
		return mem[node->id][n] = ans;
	}
	
	if (n % 2 == 0) {
		ans = dp(node->left, n / 2) + dp(node->right, n / 2);
	}
	else {
		ans = dp(node->left, n / 2) + dp(node->right, n / 2 + 1);
		ans = min(ans, dp(node->left, n / 2 + 1) + dp(node->right, n / 2));
	}

	return mem[node->id][n] = ans;
}

void solve() {
	Node* root = new Node();	

	int ans = dp(root, root->nballs);

	if (ans > 1000) {
		cout << "impossible\n";
	}
	else {
		cout<< ans / 2 << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	while (cin >> c) {
		nodecnt = 0;
		memset(mem, 0, sizeof mem);
		memset(vis, 0, sizeof vis);
		solve();
	}

	return 0;
}
