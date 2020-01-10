#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0; i<n; i++){
		int t;
		cin>>arr[i]>>t;
		if(t > k) arr[i] -= t-k;
	}
	cout<<*max_element(arr,arr+n)<<endl;
	return 0;
}
