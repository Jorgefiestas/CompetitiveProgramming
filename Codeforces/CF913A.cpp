#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main(){
	cin>>n>>m;
	if(n>26) cout<<m<<endl;
	else cout<<m%(1<<n)<<endl;
	return 0;
}
