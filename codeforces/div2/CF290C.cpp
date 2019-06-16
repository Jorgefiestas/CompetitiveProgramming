#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> words(100);
unordered_map<char, char> to;
unordered_map<char, char> from;
unordered_map<char, bool> vis;

int main(){
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>words[i];
    
    for(int i = 1; i<n; i++){
        int j = 0;
        while(words[i][j] == words[i-1][j] && j<min(words[i].size(), words[i-1].size())) j++;
        char x = words[i][j], y = words[i-1][j];
        if(to.find(y) != to.end()){
            cout<<"Impossible"<<endl;
            return 0;
        }
        to[y] = x;
    }


