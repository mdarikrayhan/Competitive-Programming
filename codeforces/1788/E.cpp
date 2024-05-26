#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int N=1e6+10;
int t[4*N];

void build(vector<int> &a,int v,int tl,int tr){
    if(tl==tr) {
        t[v]=a[tl];
    }else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=max(t[v*2],t[v*2+1]);
    }
}

int query(int v,int tl,int tr,int l,int r){
    if(l>r){
        return INT_MIN;
    }
    if(l==tl&&r==tr){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return max(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}

void update(int v,int tl,int tr,int pos,int new_val){
    if(tl==tr){
        t[v]=new_val;
    }else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }else{
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        t[v]=max(t[v*2],t[v*2+1]);
    }
}

int main(){
    IOS
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    map<ll,int> mp;
    mp[0]=0;
    vector<ll> suff(n+2);
    for(int i=n;i>=1;--i){
        suff[i]=suff[i+1]+a[i];
        mp[suff[i]]=0;
    }
    int x=0;
    for(auto &it:mp){
        it.second=x;
        x++;
    }
    vector<int> b(x,-1e9);
    build(b,1,0,x-1);
    vector<int> dp(n+1);
    for(int i=1;i<=n;++i){
        int l=query(1,0,x-1,mp[suff[i]],mp[suff[i]]);
        update(1,0,x-1,mp[suff[i]],max(l,dp[i-1]-i+1));
        dp[i]=dp[i-1];
        dp[i]=max(dp[i],query(1,0,x-1,mp[suff[i+1]],x-1)+i);
    }
    cout<<dp[n];
    return 0;
}

