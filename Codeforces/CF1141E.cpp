#include <bits/stdc++.h>
using namespace std;
long long t, hp, n, d[200001], m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>hp>>n>>d[0];
	for(int i = 1; i<n; i++)
		cin>>t, d[i] = d[i-1] + t;
	for(int i = 0; i<n; i++){
		if(-d[i] >= hp){
			cout<<i+1<<endl;
			return 0;
		}
	}
	if(d[n-1] >= 0){
		cout<<-1<<endl;
		return 0;
	}
	long long mn = *min_element(d, d+n);
	m = ((hp+mn)/-d[n-1]) + ((hp+mn)%-d[n-1] != 0);
	hp += m*d[n-1]; 
	m *= n;
	for(int i = 0; i<n; i++){
		m++;
		if(-d[i%n] >= hp) break;
	}
	cout<<m<<endl;
	return 0;
}
