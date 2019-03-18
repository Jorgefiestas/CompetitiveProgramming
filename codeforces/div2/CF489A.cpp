#include <bits/stdc++.h>
using namespace std;
int swaps;
vector<vector<int>> sw;

void swap(int* a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
	swaps++;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++) cin>>arr[i];
	for(int i = 0; i<n; i++){
		int* min = arr+i;
		for(int j = i+1; j<n; j++)
			if(arr[j] < *min) min = arr+j;
		if(arr+i == min) continue;
		swap(arr+i, min);
		sw.push_back({i, (int)(min - arr)});
	}
	cout<<swaps<<endl;
	for(vector<int> p : sw)
		cout<<p[0]<<' '<<p[1]<<endl;
	return 0;
}
