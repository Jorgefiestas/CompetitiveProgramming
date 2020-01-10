#include <bits/stdc++.h>
using namespace std;
int n, last, arr[200005];
string ans;

string equal(int i, int j){
    string temp1, temp2;
    temp1 = "L";
    temp2 = "R";
    i++, j--;
    while(arr[i] > arr[i-1]){
        temp1 += 'L';
        i++;
    }
    while(arr[j] > arr[j+1]){
        temp2 += 'R';
        j--;
    }
    return temp1.size() > temp2.size() ? temp1 : temp2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i] <= last && arr[j] <= last)
            break;
        if(arr[i] > last && arr[j] > last){
            if(arr[i] < arr[j]){
                last = arr[i];
                ans += 'L';
                i++;
            }
            else if (arr[i]>arr[j]){
                last = arr[j];
                ans += 'R';
                j--;
            }
            else{
                ans += equal(i, j);
                break;
            }
        }
        else if(arr[i] > last){
            last = arr[i];
            ans += 'L';
            i++;
        }
        else{
            last = arr[j];
            ans += 'R';
            j--;
        }
    }
    if(i == j && arr[i] > last){
        ans += 'R';
    }

    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}
