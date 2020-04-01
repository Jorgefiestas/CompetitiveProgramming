#include <bits/stdc++.h>
using namespace std;
int n, t, cnt, e[100005], o[100003];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>e[0];
	if(n < 2) cout<<1;
	else cin>>o[0];
	for(int i = 2; i<n; i++){
		cin>>t;
		if(i%2 == 0) e[i/2] += e[i/2 - 1] + t;
		else o[i/2] += o[i/2 - 1] + t;
	}
	for(int i = 0; i<n; i++){
		int e1 = 0, o1 = 0, e2=0, o2 = 0;
		if(i!=0) e1 = e[i/2 - 1 + i%2];
		if(i>1) o1 = o[i/2 - 1];
		e2 = e[n/2-1 + n%2] - e[i/2];
		if(i < n-1) o2 = o[n/2-1] - o[i/2 - 1 + i%2];
		int fe = e1 + o2;
		int fo = o1 + e2;
		if(fe == fo) cnt++;
	}
	if(n<2) return 0;
	cout<<cnt<<endl;
	return 0;
}
