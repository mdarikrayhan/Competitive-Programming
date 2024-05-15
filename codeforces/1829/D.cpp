#include <bits/stdc++.h>
using namespace std;
int n,m;
bool f;
void dfs(int u){
    if(u==m){
        f=true;
        return;
    }
    if(f)return;
    if(u==0)return;
    if(u%3)return;
    dfs(u/3);
    dfs(u/3*2);
}
void solve(){
    f=false;
    cin>>n>>m;
    if(m>n){
        cout<<"NO"<<endl;
        return;
    }
    dfs(n);
    if(f){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}