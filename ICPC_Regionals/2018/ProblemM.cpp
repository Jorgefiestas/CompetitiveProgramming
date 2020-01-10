#include <bits/stdc++.h>
using namespace std;
int n, cnt, arr[55];

int main(){
	cin>>n;

	for(int i = 0; i<n; i++)
		cin>>arr[i];

	for(int i = n-2; i>= 0; i--)
		if(arr[i] >= arr[i+1]) cnt++;

	cout<<n-cnt<<endl;

	return 0;
}
