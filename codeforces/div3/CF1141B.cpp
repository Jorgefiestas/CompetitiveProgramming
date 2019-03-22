#include <bits/stdc++.h>
using namespace std;
int n, h, a[400001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++) cin>>a[i], a[n+i] = a[i];
	int th = 0;
	for(int i = 0; i<2*n; i++){
		if(a[i] == 0){
			if(th > h) h = th;
			th = 0;
		}
		else th++;
	}
	if(th > h) h = th;
	cout<<h<<endl;
	return 0;
}
