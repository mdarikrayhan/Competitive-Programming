//either strictly inc or dec
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solve(){
    lli n;
    cin>>n;
    vector<lli> v(n);
    for(lli i=0;i<n;i++){
        cin>>v[i];
    }
    for(lli i=1;i<n-1;i++){
        //for inc
        if(v[i-1]<=v[i] && v[i]<=v[i+1]){
            v[i]=v[i-1];
        }
        //for dec
        else if(v[i-1]>=v[i] && v[i]>=v[i+1]){
            v[i]=v[i-1];
        }
    }
    vector<lli> unique;
    unique.push_back(v[0]);
    for(lli i=1;i<n;i++){
        if(v[i]!=v[i-1]){
            unique.push_back(v[i]);
        }
    }
    cout<<unique.size()<<endl;
    for(lli i=0;i<unique.size();i++){
        cout<<unique[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}