#include <bits/stdc++.h>
using namespace std;
int pfact[3001];
bool np[3001];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 2; i<=n; i++){
		if(np[i]) continue;
		for(int j = 2*i; j<=n; j+=i){
			np[j] = true;
			pfact[j]++;
		}
	}
	int count = 0;
	for(int i = 0; i<=n; i++)
		if(pfact[i] == 2) count++;
	cout<<count<<endl;
}
