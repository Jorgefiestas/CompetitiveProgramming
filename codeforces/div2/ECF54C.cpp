#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long double d;
        cin>>d;
        long double det = d*d - 4.0*d;
        if(det>=0){
            long double b = (d + sqrt(det))/2.0;
            long double a = d - b;
            printf("Y %.9Lf %.9Lf \n", b, a);
        }
        else cout<<"N"<<endl;
    }
	return 0;
}
