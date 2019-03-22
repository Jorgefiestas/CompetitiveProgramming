#include <bits/stdc++.h>
using namespace std;
int n, t, arr[200001];

bool check(){
	unordered_map<int, bool> count;
	for(int i = 0; i<n; i++)
		count[arr[i]] = true;
	for(int i = 1; i<= n; i++)
		if(!count[i]) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int temp = 0;
	for(int i = 1; i< n; i++) cin>>t, arr[i] = arr[i-1] + t;
	int d = *min_element(arr, arr+n+1);
	for(int i = 0; i<n; i++)
		arr[i] += (1-d);
	if(check()) for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
	else cout<<-1;
	cout<<endl;
	return 0;
}
