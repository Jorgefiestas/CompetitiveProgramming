#include <bits/stdc++.h>
using namespace std;
long long arr[31], n, l, total;

long long solve(long long x){
	if(x<=0) return 0;
	int i = log2(x);
	if(i >= n-1) return arr[n-1]*(x/(1<<(n-1))) + solve(x%(1<<(n-1)));
	long long left = arr[i] + solve(x-(1<<i));
	return min(left, arr[i+1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l;
	for(int i = 0; i<n; i++)
		cin>>arr[i];
	for(int i = n-1; i>0; i--)
		arr[i-1] = min(arr[i-1], arr[i]);
	for(int i = 0; i<n-1; i++)
		arr[i+1] = min(2*arr[i], arr[i+1]);
	cout<<solve(l)<<endl;
	return 0;
}
