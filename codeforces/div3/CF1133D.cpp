#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> PII;
map<PII, int> d;
int n, c, z, a[200001];

int gcd(int a, int b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)
		cin>>a[i];
	for(int i = 0; i<n; i++){
		cin>>c;
		if(a[i] == 0 && c == 0) z++;
		if(a[i] == 0) continue;
		if(c == 0) a[i] = 1;
		int g = gcd(c, a[i]);
		d[make_pair(a[i]/g, c/g)]++;
	}
	int mx = 0;
	for(auto it : d)
		if(mx < it.second) mx = it.second;
	cout<<mx + z<<endl;
	return 0;
}
