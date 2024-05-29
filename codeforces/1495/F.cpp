#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define ll long long
int n,q;
struct rupq{
    ll t[2*N];
    void pointAdd(int i,ll v){
        for(t[i+=(n+2)]+=v;i>>=1;)t[i]=t[i<<1]+t[i<<1|1];
    }
    ll rangeQuery(int l,int r){
        ll ret=0;
        for(l+=n+2,r+=n+3;l<r;l>>=1,r>>=1){
            if(l&1)ret+=t[l++];
            if(r&1)ret+=t[--r];
        }
        return ret;
    }
    void rangeAdd(int l,int r,ll v){
        l=max(l,0);
        r=min(r,n);
        if(l>r)return;
        pointAdd(l,v);
        pointAdd(r+1,-v);
    }
    ll query(int i){
        return rangeQuery(0,i);
    }
}calc;
int arr[N];
ll nxt[N],jump[N];
vector<int>qq[N];
map<int,ll>ans[N];
int qar[N];
ll dp[N];
signed main(){
    iostream::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    for(int a=0;a<n;++a)cin>>arr[a];
    for(int a=0;a<n;++a)cin>>nxt[a];
    for(int a=0;a<n;++a)cin>>jump[a];
    //
    set<int>pt;
    pt.insert(0);
    pt.insert(n);
    for(int a=0;a<q;++a){
        int x;cin>>x;--x;
        qar[a]=x;
        if(x==0)continue;
        auto it=pt.find(x);
        if(it!=pt.end()){
            qq[*prev(it)].push_back(*next(it));
            pt.erase(x);
        }
        else{
            auto it=pt.insert(x).first;
            qq[*it].push_back(*next(it));
            qq[*prev(it)].push_back(*it);
        }
    }
    qq[0].push_back(n);
    //
    arr[n]=n+1;
    vector<int>incr=vector<int>{n};
    for(int a=n-1;a>=0;--a){
        while(arr[incr.back()]<arr[a])incr.pop_back();
        dp[a]=calc.query(incr.back())+nxt[a];
        calc.rangeAdd(incr.back(),n,nxt[a]+min(dp[a],jump[a])-dp[a]);
        calc.rangeAdd(a+1,incr.back()-1,nxt[a]);
        dp[a]=min(dp[a],jump[a]);
        incr.push_back(a);
        for(auto r:qq[a]){
            ans[a][r]=calc.query(r);
        }
    }
    //
    pt.clear();pt.insert(0);pt.insert(n);
    ll curAns=ans[0][n];
    for(int a=0;a<q;++a){
        int x=qar[a];
        if(x!=0){
            auto it=pt.find(x);
            if(it!=pt.end()){
                curAns-=ans[*prev(it)][*it];
                curAns-=ans[*it][*next(it)];
                curAns+=ans[*prev(it)][*next(it)];
                pt.erase(x);
            }
            else{
                auto it=pt.insert(x).first;
                curAns+=ans[*prev(it)][*it];
                curAns+=ans[*it][*next(it)];
                curAns-=ans[*prev(it)][*next(it)];
            }
        }
        cout<<curAns<<"\n";
    }
}