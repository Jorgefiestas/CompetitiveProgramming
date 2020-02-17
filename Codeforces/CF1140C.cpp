#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> times[1000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	int ti, bi;
	for (int i = 0; i < n; i++) {
		cin >> ti >> bi;
		times[bi].emplace_back(ti);
	}

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	long long sm = 0;
	long long ans = 0;

	for (long long b = 1e6; b > 0; b--) {
		for (long long t : times[b]) {
			if (pq.size() < k) {
				sm += t;
				pq.push(t);
			}
			else if (t > pq.top()) {
				sm -= pq.top();
				sm += t;
				pq.pop();
				pq.push(t);
			}
		}

		ans = max(ans, sm * b);
	}

	cout << ans << endl;
}
