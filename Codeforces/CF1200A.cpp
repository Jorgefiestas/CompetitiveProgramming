#include <bits/stdc++.h>
using namespace std;
int n;
char c;
bool r[10];

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>c;
        if(c == 'L'){
            int i = 0;
            while(r[i]) i++;
            r[i] = true;
        }
        else if(c == 'R'){
            int i = 9;
            while(r[i]) i--;
            r[i] = true;
        }
        else
            r[c - '0'] = false;
    }
    for(int i = 0; i < 10; i++){
        if(r[i]) cout<<1;
        else cout<<0;
    }
    cout<<endl;

    return 0;
}
