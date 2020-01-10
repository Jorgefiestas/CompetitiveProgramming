#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> al(3010);
int sc[3010];

void ln(int v, int d){
	if(!al[v].size()){
		sc[d]++;
		return;
	}
	for(int c : al[v])
		ln(c, v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin>>n;
	for(int i = 1; i<n; i++){
		cin>>p;
		p--;
		al[p].emplace_back(i);
	}
	ln(0, -1);
	for(int i = 0; i<n; i++){
		if(sc[i]<3 && al[i].size()){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}
