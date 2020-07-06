#include <bits/stdc++.h>
using namespace std;
int n;

int sum_digits(int x){
    int ans = 0;
    while(x){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main(){
    cin>>n;
    
    while(sum_digits(n)%4 != 0) n++;

    cout<<n<<endl;
}
