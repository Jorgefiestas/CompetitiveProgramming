#include <bits/stdc++.h>
using namespace std;
long long T, n, num, arr[301];

long long factor(){
    long long factors = 0;
    for(long long i = 2; i*i <= num; i++){
        if(num%i == 0) factors+=2;
        if(i*i == num) factors--;
    }
    return factors;
}

long long divisors(){
   sort(arr, arr+n);
   num = arr[0]*arr[n-1];
   for(int i =1; i<=n/2; i++){
       if(num != arr[i]*arr[n-i-1]) return -1;
   }
   if(factor() != n) return -1;
   return num;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--){
       cin>>n; 
       for(int i = 0; i<n; i++)
           cin>>arr[i];
       cout<<divisors()<<endl;
    }
    return 0;
}
