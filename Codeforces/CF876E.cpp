#include <bits/stdc++.h>
using namespace std;
int n, a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(INT_MAX);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (pq.top() < a) {
			ans -= (long long) pq.top();
			ans += (long long) a;
			pq.pop();
			pq.push(a);
		}
		pq.push(a);
	}

	cout << ans << '\n';

	return 0;
}
