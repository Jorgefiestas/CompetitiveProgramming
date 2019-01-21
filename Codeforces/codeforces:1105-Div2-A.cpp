#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int mini(int a, int b){
	if(a<b)
		return a;
	return b;
}

int main(){

	int n;
	scanf("%d", &n);

	vector<int> count(1001,0);

	for(int i = 0; i<n; i++){
		int t;
		scanf("%d", &t);
		count[t]++;
	}

	int t = 0;
	int min = INT_MAX;

	for(int i = 2; i<1000; i++){
		int temp = 0;
		for(int j = 0; j<1000; j++){
			if(j>=i-1 && j<=i+1) continue;
			temp += count[j]*mini(abs(j-i-1),abs(j-i+1));
		}
		if(temp<min){
			min = temp;
			t = i;
		}
	}

	cout<<t<<" "<<min<<endl;

	return 0;
}