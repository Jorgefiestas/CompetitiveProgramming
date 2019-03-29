#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int, bool> on;

int main(){
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		int k;
		cin>>k;
		for(int j = 0; j<k; j++){
			int t;
			cin>>t;
			on[t] = true;
		}
	}
	for(int i = 1; i<=m; i++){
		if(!on[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
