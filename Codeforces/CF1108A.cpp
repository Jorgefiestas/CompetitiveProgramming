#include <bits/stdc++.h>
using namespace std;

int main(){

	int q;
	scanf("%d",&q);

	int res[q][2];

	for(int i = 0; i<q; i++){
		int l1,l2,r1,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		if(l1 == r2) r2 = l2;
		res[i][0] = l1;
		res[i][1] = r2;
	}

	for(int i = 0; i<q; i++){
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}

	return 0;
}
