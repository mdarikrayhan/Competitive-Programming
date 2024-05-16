#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int idx=0;
    int stop=n;
    map<int,int>mp;
        int print=0;
    while(stop>0){
        if(idx<n){
            cin>>a[idx];
            mp[a[idx]]++;
            idx++;
        }
            
        // cout<<"stop = "<<stop<<"  map = "<<mp[stop];
        while(mp[stop]>0){
            cout<<stop<<" ";
            stop--;
            print =1;
        }
        cout<<endl;
        
       
    }
}