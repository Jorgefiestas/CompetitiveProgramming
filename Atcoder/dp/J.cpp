#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n;
double mem[N][N][N];
bool vis[N][N][N];

double dp(int one, int two, int three) {
	if (one == 0 && two == 0 && three == 0) {
		return 0;
	}
	if (mem[one][two][three]) {
		return mem[one][two][three];
	}
	vis[one][two][three] = true;

	int t = one + two + three;

	double ans = (double) n / t;

	if (one) {
		ans += (double) one / t * dp(one - 1, two, three);
	}
	if (two) {
		ans += (double) two / t * dp(one + 1, two - 1, three);
	}
	if (three) {
		ans += (double) three / t * dp(one, two + 1, three - 1);
	}
	
	return mem[one][two][three] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x, cnt[4] = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}

	cout << setprecision(15) << dp(cnt[1], cnt[2], cnt[3]) << '\n';

	return 0;
}
