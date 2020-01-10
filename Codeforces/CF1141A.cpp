#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main(){
	cin>>n>>m;
	int d = m/n;
	int count = 0;
	while(d%2 == 0) count++, d/=2;
	while(d%3 == 0) count++, d/=3;
	if(d!=1 || m%n)cout<<-1<<endl;
	else cout<<count<<endl;
	return 0;
}
