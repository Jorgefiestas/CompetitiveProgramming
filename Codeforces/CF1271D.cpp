#include <bits/stdc++.h>
using namespace std;
int n, m, k, score;
int a[5005], b[5005], c[5005], last[5005];
vector<int> toAdd[5005];
priority_queue<int, vector<int>, greater<int>> defended;

void pop() {
	score -= defended.top();
	defended.pop();
	k++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		last[i] = i;
	}


	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		last[v] = max(last[v], u);
	}

	for (int i = 1; i <= n; i++) {
		toAdd[last[i]].emplace_back(i);
	}

	for (int i = 1; i <= n; i++) {
		while (!defended.empty() && k < a[i]) {
			pop();
		}
		if (k < a[i] && defended.empty()) {
			cout << -1 << endl;
			return 0;
		}

		k += b[i];

		for (int ta : toAdd[i]) {
			if (k > 0) {
				defended.push(c[ta]);
				score += c[ta];
				k--;
			}
			else {
				defended.push(c[ta]);
				score += c[ta];
				pop();
				k = 0;;
				
			}
		}
	}

	cout << score << endl;

	return 0;
}
