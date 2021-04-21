struct MaxFlow {
	int capacity[N][N];
	vector<int> adj[N];

	int bfs(int s, int t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1);

		parent[s] = -2;
		queue<pii> q;
		q.push({s, 1000});

		while (!q.empty()) {
			auto [cur, flow] = q.front();
			q.pop();

			for (int next : adj[cur]) {
				if (parent[next] == -1 && capacity[cur][next]) {
					parent[next] = cur;
					int new_flow = min(flow, capacity[cur][next]);

					if (next == t)
						return new_flow;

					q.push({next, new_flow});
				}
			}
		}

		return 0;
	}

	int maxflow(int s, int t) {
		int flow = 0;
		vector<int> parent(N);

		int new_flow = bfs(s, t, parent);
		while (new_flow) {
			flow += new_flow;
			int cur = t;

			while (cur != s) {
				int prev = parent[cur];
				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}

			new_flow = bfs(s, t, parent);
		}

		return flow;
	}
};

