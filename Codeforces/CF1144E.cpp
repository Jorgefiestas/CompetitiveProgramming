#include <bits/stdc++.h>
using namespace std;
int n;
string a, b, ans;
vector<int> ab(200005);

void sum(){
	for(int i = n-1; i>=0; i--){
		ab[i+1] += (a[i] - 'a') + (b[i] - 'a');
		ab[i]  += ab[i+1]/26;
		ab[i+1] = ab[i+1]%26;
	}
}

void divide(){
	for(int i = 0; i<n+1; i++){
		ab[i+1] += (ab[i]%2)*26;
		ab[i] = ab[i]/2;
	}
	for(int i = 1; i<=n; i++)
		ans += ab[i] + 'a';
}

int main(){
	cin>>n>>a>>b;
	sum();
	divide();
	cout<<ans<<endl;
	return 0;
}
