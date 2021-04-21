#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int,int,int>

int root(vector<int> &arr, int i) {
	while (arr[i] != i) {
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

void join(vector<int> &arr, int a, int b) {
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	arr[root_a] = arr[root_b];
}

bool find(vector<int> &arr, int a, int b) {
	return root(arr, a) == root(arr, b);
}

int main(){
	int V, E;
	scanf("%d %d", &V, &E);
	vector<edge> edges(E);

	for (int i = 0; i<E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		edges[i] = make_tuple(w,u,v);
	}

	sort(edges.begin(), edges.end());

	vector<int> union_set(V);

	for (int i = 0; i < V; i++) {
		union_set[i] = i;
	}

	int i = 0;
	int count = 0;

	while (i < E) {
		int w = get<0>(edges[i]);
		vector<pair<int,int>> to_add;

		int count_pos = 0; 

		while (get<0>(edges[i]) == w) {
			int u = get<1>(edges[i]);
			int v = get<2>(edges[i]);
			if (!find(union_set, u,v)) {
				to_add.emplace_back(make_pair(u,v));
				count_pos++;
			}
			i++;

			if (i>=E) break;
		}

		int count_act = 0;
		for (pair<int,int> e : to_add) {
			int u = e.first;
			int v = e.second;
			if (!find(union_set, u,v)) {
				count_act++;
				join(union_set,u,v);
			}
		}

		count += (count_pos - count_act);
	}
	cout << count << '\n';


	return 0;
}
