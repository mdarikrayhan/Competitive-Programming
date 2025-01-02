// LUOGU_RID: 159723893
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for (int i=j;i<=k;++i)
int const N=2e3+10;
int n,x[N],y[N],a[N],id=-1;
struct Dsu{
    int fa[N];
    inline void init(int n){rep(i,1,n) fa[i]=i;};
    inline int find(int x){return (x==fa[x])?(x):(fa[x]=find(fa[x]));}
    inline void merge(int x,int y){fa[find(x)]=find(y);}
}D;
void solve(){
    cin>>n,D.init(n);
    rep(i,1,n) cin>>x[i]>>y[i]>>a[i];
    rep(i,1,n){
        if (a[i]==i) continue;
        if (id==-1) id=i;
        if (make_pair(x[i],y[i])<make_pair(x[id],y[id])) id=i;
    }
    if (id==-1) return cout<<"0\n",void();
    vector<int>b;
    rep(i,1,n){
        if (a[i]==i || i==id) continue;
        b.push_back(i);
    }
    sort(all(b),[](int i,int j){return atan2(y[i]-y[id],x[i]-x[id])<atan2(y[j]-y[id],x[j]-x[id]);});
    rep(i,1,n) D.merge(i,a[i]);
    b.push_back(b[1]);
    vector< pair<int,int> >ans;
    rep(i,0,(int)b.size()-2)
        if (D.find(b[i])!=D.find(b[i+1])) D.merge(b[i],b[i+1]),swap(a[b[i]],a[b[i+1]]),ans.push_back({b[i],b[i+1]});
    while (a[id]!=id) ans.push_back({id,a[id]}),swap(a[id],a[a[id]]);
    cout<<ans.size()<<'\n';
    for (auto i:ans) cout<<i.first<<' '<<i.second<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}