#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);

	vector<int> arr(n);

	int otk = 0;

	for(int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
		if(arr[i]<= x)
			otk++;
	}

	if(x>y){
		cout<<n<<endl;
		return 0;
	}

	cout<<otk/2 + otk%2<<endl;
	
	return 0;
}
