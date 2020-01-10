#include<bits/stdc++.h>
using namespace std;
long long n, m, k, del, e, op, temp, arr[100005];

int main(){
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++)
        cin>>arr[i];
    
    for(int i = 0; i < m; i++){
        if(arr[i] - del < e){
            temp++;
            continue;
        }
        else{
            del += temp;
            op++;
            temp = 1;
            e = ((arr[i] - 1LL - del)/k)*k + k + 1LL;
        }
    }

    cout<<op<<endl;

    return 0;
}
