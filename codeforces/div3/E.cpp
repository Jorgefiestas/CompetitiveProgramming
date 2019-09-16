#include <bits/stdc++.h>
using namespace std;
int n, t, cnt, w[150005];
const int N = 150003;

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        w[t]++;
    }

    for(int i = 1; i < N; i++){
        if(w[i - 1]){
            cnt++;
            w[i - 1]--;
        }
        else if(w[i]){
            cnt++;
            w[i]--;
        }
        else if(w[i + 1]){
            cnt++;
            w[i + 1]--;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
