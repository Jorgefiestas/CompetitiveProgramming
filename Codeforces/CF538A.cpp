#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z,a,b,c;
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d %d %d",&a,&b,&c);
	if(x>a){
		cout<<"NO"<<endl;
		return 0;
	}
	int t = a + b - x;
	if(y>t){
		cout<<"NO"<<endl;
		return 0;
	}
	t -= y;
	if(z>t+c){
        cout<<"NO"<<endl;
        return 0;
    }
	cout<<"YES"<<endl;
	return 0;
}
