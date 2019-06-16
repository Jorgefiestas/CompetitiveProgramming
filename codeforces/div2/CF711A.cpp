#include <bits/stdc++.h>
using namespace std;
int n;
bool pos;
vector<string> rows(1000);

int main(){
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>rows[i];
    }

    for(int i = 0; i<n; i++){
        if(rows[i][0] == 'O' &&  rows[i][1] == 'O'){
            rows[i][0] = '+';
            rows[i][1] = '+';
            pos = true;
            break;
        } 
        else if(rows[i][3] == 'O' &&  rows[i][4] == 'O'){
            rows[i][3] = '+';
            rows[i][4] = '+';
            pos = true;
            break;
        } 
    }

    if(!pos){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i = 0; i<n; i++)
        cout<<rows[i]<<endl;

   return 0;
}
