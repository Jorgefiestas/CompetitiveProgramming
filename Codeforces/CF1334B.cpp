#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n, a[N];
long long x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> x;

		long long sum = 0;
		int ppl = n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += (long long) a[i];
		}

		sort(a, a + n);
		
		int i = 0;
		while (i < n && sum / (1LL * ppl) < x) {
			sum -= (long long) a[i];
			ppl--;
			i++;
		}

		cout << ppl << endl;
	}
	
	return 0;
}
