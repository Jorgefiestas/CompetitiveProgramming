#include <bits/stdc++.h>
using namespace std;
long long sv, cnt, arr[1000005];
string str;

int main(){
    cin>>str;

    for(int i = 0; i<str.size(); i++){
        if(i < str.size() - 1 && str[i] == 'v' && str[i + 1] == 'v'){
            sv++;
        }
        else if(str[i] == 'o'){
            arr[i] = sv;
        }
    }

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'o'){
            cnt += arr[i]*(sv - arr[i]);
        }
    }

    cout<<cnt<<endl;
    return 0;
}
