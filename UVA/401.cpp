#include <bits/stdc++.h>
using namespace std;
int n;
string str;
unordered_map<char, char> rev;

bool is_pal(){
    for(int i = 0; i<n/2; i++){
        if(str[i] != str[n-1-i])
            return false;
    }

    return true;
}

bool is_mir(){
    for(int i = 0; i<n/2; i++){
        if(str[i] != rev[str[n-1-i]])
            return false;
    }
    if(n%2 == 1 && str[n/2] != rev[str[n/2]])
        return false;

    return true;
}

int main(){
    rev['A'] = 'A';
    rev['E'] = '3';
    rev['3'] = 'E';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['J'] = 'L';
    rev['L'] = 'J';
    rev['M'] = 'M';
    rev['O'] = 'O';
    rev['S'] = '2';
    rev['2'] = 'S';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = 'X';
    rev['Y'] = 'Y';
    rev['Y'] = 'Y';
    rev['Z'] = '5';
    rev['5'] = 'Z';
    rev['1'] = '1';
    rev['8'] = '8';

    while(cin>>str){
        n = str.size();

        bool p, m;
        p = is_pal();
        m = is_mir();
        
        if(p && m)
            cout<<str<<" -- is a mirrored palindrome."<<endl;
        else if(p)
            cout<<str<<" -- is a regular palindrome."<<endl;
        else if(m)
            cout<<str<<" -- is a mirrored string."<<endl;
        else 
            cout<<str<<" -- is not a palindrome."<<endl;
        cout<<endl;
    }

    return 0;
}
