#include <bits/stdc++.h>
using namespace std;
long double d;
int t;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%Lf", &d);
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
