#include <bits/stdc++.h>
using namespace std;
int n, temp, pr[43], cnt[43];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pr[8] = 4;
    pr[15] = 8;
    pr[16] = 15;
    pr[23] = 16;
    pr[42] = 23;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>temp;

        if(temp == 4){
            cnt[4]++;
        }
        else if(cnt[pr[temp]]){
            cnt[pr[temp]]--;
            cnt[temp]++;
        }
    }
    
    cout<<n - 6*cnt[42]<<endl;
    return 0;
}
