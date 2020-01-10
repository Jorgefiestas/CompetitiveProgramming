#include <bits/stdc++.h>
using namespace std;
int n, k;
string num;

int main(){
    cin>>n>>k;
    cin>>num;

    if(n == 1){
        if(k)
            cout<<0<<endl;
        else
            cout<<num<<endl;
        return 0;
    }

    if(k && num[0] != '1'){
        num[0] = '1';
        k--;
    }

    for(int i = 1; k && i < n; i++){
        if(num[i] != '0'){
            num[i] = '0';
            k--;
        }
    }

    cout<<num<<endl;

    return 0;
}
