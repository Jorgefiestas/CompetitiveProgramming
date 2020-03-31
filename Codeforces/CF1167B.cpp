#include <bits/stdc++.h>
using namespace std;
vector<int> sn = {4 , 8, 15, 16, 23, 42};
int sum, q[4], sol[6];

int main(){
    for(int x : sn)
        sum += x;
    reverse(sn.begin(), sn.end());
    for(int i = 2; i<6; i++){
        cout<<"? "<<1<<" "<<i<<endl;
        fflush(stdout);
        cin>>q[i-2];
    }

    for(int x : sn){
        if(q[0]%x == 0 && q[1]%x == 0 && q[2]%x == 0 && q[3]%x == 0){
            sol[0] = x;
            break;
        }
    }

    for(int i = 1; i<=4; i++){
        sol[i] = q[i-1]/sol[0];
    }
    
    sol[5] = sum;

    for(int i = 0; i<5; i++)
        sol[5] -= sol[i];

    cout<<"! ";
    for(int i = 0; i<6; i++)
        cout<<sol[i]<<" ";
    cout<<endl;

    return 0;
}
