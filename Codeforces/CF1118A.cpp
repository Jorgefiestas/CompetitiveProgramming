#include <bits/stdc++.h>
using namespace std;
int q;
long long n, a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>q;
	while(q--){
		cin>>n>>a>>b;
		if(a*2 < b){
			cout<<a*n<<endl;
			continue;
		}
		long long o1 = b*(n/2) + a*(n%2);
		cout<<o1<<endl;
	}
	return 0;
}
