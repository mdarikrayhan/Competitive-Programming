#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,k,idx,a[N+5],be[N+5],en[N+5];
bool vs[N+5];
vector <int> g[N+5];
void dfs(int i){
    vs[i]=true;
    be[i]=++idx;
    for (int j : g[i])
        if (!vs[j])
            dfs(j);
    en[i]=idx;
}
int ST[4*N+5],Lz[4*N+5];
void Pus(int id, int l, int r){
    if (!Lz[id]) return;
    if (l!=r){
        Lz[id<<1]+=Lz[id];
        Lz[id<<1|1]+=Lz[id];
    }
    ST[id]+=Lz[id];
    Lz[id]=0;
}
void Update(int id, int l, int r, int x, int y, int val){
    Pus(id,l,r);
    if (l>y || r<x) return;
    if (l>=x && r<=y){
        Lz[id]+=val;
        Pus(id,l,r);
        return;
    }
    int md=l+r>>1;
    Update(id<<1,l,md,x,y,val);
    Update(id<<1|1,md+1,r,x,y,val);
    ST[id]=max(ST[id<<1],ST[id<<1|1]);
}
int Get(int id, int l, int r, int x, int y){
    Pus(id,l,r);
    if (l>y || r<x) return -1e9;
    if (l>=x && r<=y) return ST[id];
    int md=l+r>>1;
    return max(Get(id<<1,l,md,x,y),Get(id<<1|1,md+1,r,x,y));
}
void Solve(){
    cin>>n>>k;
    for (int i=1;i<=n;++i) cin>>a[i];
    stack <int> st;
    for (int i=n;i>=1;--i){
        if (st.size()){
            while (a[st.top()]<=a[i]){
                st.pop();
                if (st.empty()) break;
            }
            if (st.size()) g[st.top()].push_back(i);
        }
        st.push(i);
    }
    for (int i=n;i>=1;--i)
        if (!vs[i])
            dfs(i);
    for (int i=1;i<=k;++i)
        Update(1,1,n,be[i],en[i],1);
    cout<<Get(1,1,n,1,n)<<' ';
    for (int i=k+1;i<=n;++i){
        Update(1,1,n,be[i],en[i],1);
        Update(1,1,n,be[i-k],en[i-k],-1e9);
        cout<<Get(1,1,n,1,n)<<' ';
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen ("FILE.INP","r",stdin);
    // freopen ("FILE.OUT","w",stdout);
    int t=1;
    // cin>>t;
    while (t--) Solve();
}
