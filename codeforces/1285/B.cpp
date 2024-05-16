#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define pb push_back
#define rep(num,i,n) for(int i=num;i<n;i++)
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define vi vector<int>

void solve(){
    int n;cin>>n;
    vi v(n);
    int sum=0;
    rep(0,i,n){
        cin>>v[i];
        sum+=v[i];
    }
    int ans=0,c=0;
    rep(0,i,n-1){
        c+=v[i];
        if(c<0)c=0;
        ans=max(c,ans);
    }
    c=0;
    rep(1,i,n){
        c+=v[i];
        if(c<0)c=0;
        ans=max(c,ans);
    }
    if(ans>=sum)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }

}