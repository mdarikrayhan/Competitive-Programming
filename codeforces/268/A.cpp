#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,home[30],guest[30],count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>home[i]>>guest[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(home[i]==guest[j]){
                count++;
            }
        }
    }
    cout<<count;
}