#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> rem;
int g;

int main(){
	int n, k;
	cin>>n>>k;
	for(int i = 0; i<n; i++){
		int t;
		cin>>t;
		int rt = t%k;
		if(rem[rt]){
			rem[rt]--;
			g++;
			continue;
		}
		if(rt == 0){
			rem[0]++;
			continue;
		}
		rem[k-rt]++;
	}
	cout<<2*g<<endl;
	return 0;
}
