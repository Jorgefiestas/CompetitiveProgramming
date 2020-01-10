#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1000006;
int t, n, q, arr[maxn], res[maxn];
vector<pii> P;

void solve(){

	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
		P.push_back({arr[i], i});
	}
	arr[n + 1] = 0;
	sort(P.begin(), P.end());

	int d, j = 0, cnt = 1;

	for(int i = 0; i < q; i++){
		cin>>d;
		while(j < n && P[j].first <= d){
			int k = P[j].second;
			arr[k] = 0;
			if(arr[k - 1] && arr[k + 1]){
				cnt++;
			}
			if(!arr[k - 1] && !arr[k + 1]){
				cnt--;
			}
			j++;
		}
		cout<<cnt<<" ";
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	while(t--){
		P.clear();
		solve();
	}

	return 0;
}
