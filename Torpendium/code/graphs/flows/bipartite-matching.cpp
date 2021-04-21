// Kuhn Algorithm

struct BipartiteMatching {
	int n, match[N];
	bool used[N];
	vector<int> adjList[N];

	bool kuhn(int v) {
		if (used[v])
			return false;

		used[v] = true;
		for (int u : adjList[v]) {
			int mt = match[u];
			if (mt == -1 || kuhn(mt)) {
				match[u] = v;
				return true;
			}
		}

		return false;
	}

	int operator()() {
		for (int i = 1; i <= n; i++) {
			memset(used, 0, sizeof used);
			kuhn(i);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (match[i] == -1) continue;
			ans += 1;
		}

		return ans;
	}
};

// Hopcroft-Karp Algorithm

struct BipartiteMatching {
	int n, m, dist[N], match[N];
	vector<int> adjList[N];

	vector<int> &operator[](int idx) {
		return adjList[idx];
	}

	bool bfs() {
		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (match[i] == 0) {
				dist[i] = 0;
				q.push(i);
			}
			else {
				dist[i] = INT_MAX;
			}
		}

		dist[0] = INT_MAX;

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			if (v == 0) continue;

			for (int u : adjList[v]) {
				if (dist[match[u]] == INT_MAX) {
					dist[match[u]] = dist[v] + 1;
					q.push(match[u]);
				}
			}
		}

		return dist[0] != INT_MAX;
	}

	bool dfs(int v) {
		if (v == 0) 
			return true;

		for (int u : adjList[v]) {
			if (dist[match[u]] != dist[v] + 1) continue;
			if (dfs(match[u])) {
				match[u] = v;
				match[v] = u;
				return true;
			}

		}
		dist[v] = INT_MAX;
		return false;
	}

	int operator()() {
		int matching = 0;

		while (bfs()) {
			for (int i = 1; i <= n; i++) {
				if (match[i] == 0 && dfs(i)) {
					matching += 1;
				}
			}
		}

		return matching;
	}
};
