#include <bits/stdc++.h>
using namespace std;
long long n, k, pi;

int error(int e){
	cout<<e<<endl;
	return 0;
}

int main(){
	cin>>n>>k;
	if(k < n/2) return error(-1);
	if(n == 1 && k != 0) return error(-1);
	if(n == 1 && !k) return error(1);
	int x = (k - (n-2)/2);
	vector<long long> arr(n);
	arr[0] = x;
	arr[1] = 2*x;
	int j = 1;
	for(int i = 1; i<n/2; i++){
		while(j == x || j+1 == x) j++;
		while(j == 2*x || j+1 == 2*x) j++;
		arr[2*i] = j++;	
		arr[2*i+1] = j++;
	}
	if(n%2){
		arr[n-1] = j;
		while(j == x ||  j == 2*x) arr[n-1] = ++j;
	}
	for(int el : arr)
		cout<<el<<" ";
	cout<<endl;
	return 0;
}
