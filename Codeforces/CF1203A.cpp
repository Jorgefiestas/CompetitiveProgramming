#include <bits/stdc++.h>
using namespace std;
int T, n, arr[300];

bool cc(){
    int s;
    for(s = 0; s < n; s++){
        if(arr[s] == 1) break;
    }

    for(int i = 1; i < n; i++){
        if(arr[(s + i)%n] != arr[(s + i - 1)%n] + 1)
            return false;
    }

    return true;
}

bool ccc(){
    int s;
    for(s = 0; s < n; s++){
        if(arr[s] == n) break;
    }

    for(int i = 1; i < n; i++){
        if(arr[(s + i)%n] != arr[(s + i - 1)%n] - 1)
            return false;
    }

    return true;
}

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        if(cc() || ccc())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
