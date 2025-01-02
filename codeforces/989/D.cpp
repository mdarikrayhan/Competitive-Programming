#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
using namespace std; typedef long long ll;
constexpr int N=1e5+5; using pii = pair<int,int>;
int n; ll L,W; vector<ll> A[2],B[2];
ll solve(vector<ll> a,vector<ll> b){
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    debug(a,b);
    ll res=0; auto it=b.begin();
    for(ll x:a){
        while(it!=b.end()&&(L+*it)*(W-1)<=x*(W+1)) it++;
        res+=it-b.begin();
    }
    return res;
}
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    cin>>n>>L>>W; int qwq=0;
    For(i,1,n){
        ll x,v; cin>>x>>v; if(x<0&&x+L>0) { qwq=v; continue; }
        if(x>=0) (v==1?A[0]:B[0]).emplace_back(x);
        else (v==-1?A[1]:B[1]).emplace_back(-(x+L));
    }
    ll ans=1ll*A[0].size()*B[0].size()+1ll*A[1].size()*B[1].size()+1ll*B[0].size()*B[1].size(); For(o,0,1) ans-=solve(A[o],B[o]);
    debug(ans);
    if(qwq==1) ans+=B[0].size(); else if(qwq==-1) ans+=B[1].size();
    cout<<ans<<'\n';
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: April 30 Tue, 21 : 27 : 53