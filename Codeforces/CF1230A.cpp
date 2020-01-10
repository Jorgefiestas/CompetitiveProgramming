#include <bits/stdc++.h>
using namespace std;
int sm, a[5];

bool poss(int idx, int s){
    if(idx == 4){
        if(s == sm/2)
            return true;
        return false;
    }

    if(poss(idx + 1, s))
        return true;

    return poss(idx + 1, s + a[idx]);
}

int main(){
    for(int i = 0; i < 4; i++){
        cin>>a[i];
        sm += a[i];
    }

    if(sm % 2){
        cout<<"NO"<<endl;
        return 0;
    }

    if(poss(0, 0))
        cout<<"YES"<<endl;
    
    else
        cout<<"NO"<<endl;

    return 0;
}
