// LUOGU_RID: 159756458
#include<bits/stdc++.h>
using namespace std;
namespace BK0717{
#define il inline
#define ve vector
#define x first
#define y second
#define ep emplace
#define pb emplace_back
#define de(bk) #bk,'=',bk
#define all(b) begin(b),end(b)
#define rll(k) rbegin(k),rend(k)
#ifdef Bella
ifstream cin("BK.in");ofstream cout("BK.out");
#elif Asoul
ifstream cin("7.in");ofstream cout("7.out");
#endif
il bool cn(auto&x,auto y){return x>y?x=y,true:false;}
il bool cx(auto&x,auto y){return x<y?x=y,true:false;}
il void clg(auto x){cerr<<x;}il void clg(auto x,auto...y){clg(x),clg(y...);}
using LL=long long;using db=double;using pii=pair<int,int>;
const int inf=1<<30;
struct DS
{
  struct DSU
  {
    ve<int>f,L,R;
    il void _I(int n){f.assign(n,0),iota(all(f),0),L.reserve(n),R.reserve(n);}
    int F(int x){return x^f[x]?f[x]=F(f[x]):x;}
    il void _M(int x,int y)
    {
      x=F(x),y=F(y);
      if(x^y) swap(x,y),f[x]=y,cn(L[y],L[x]),cx(R[y],R[x]);
    }
    il bool _Q(int x,int y){return F(x)==F(y);}
    il int push(int l,int r){return L.pb(l),R.pb(r),L.size()-1;}
  }S;
  ve<ve<int>>t;
  int N;
  DS(int n,int m){S._I(m),t.assign(4<<__lg(N=n),{});}
  #define ls (o<<1)
  #define rs (ls|1)
  #define mid (l+r>>1)
  #define Lt ls,l,mid
  #define Rt rs,mid,r
  void _M(int o,int l,int r,int ql,int qr,int x)
  {
    if(ql<=l&&r<=qr) {
      t[o].pb(x);
      return;
    }
    if(ql<mid) _M(Lt,ql,qr,x);
    if(mid<qr) _M(Rt,ql,qr,x);
  }
  il void _M(int x){_M(1,0,N,S.L[x],S.R[x],x);}
  void _M(int o,int l,int r,int x,int id)
  {
    for(int x:t[o]) S._M(id,x);
    t[o].clear();
    if(r-l>1) x<mid?_M(Lt,x,id):_M(Rt,x,id);
  }
  il void _M(int x,int id){_M(1,0,N,x,id);}
  il bool _Q(int x,int y) // x->y
  {
    x=S.F(x),y=S.F(y);
    return S.L[y]<=S.L[x]&&S.R[x]<=S.R[y];
  }
  il int push(int l,int r){return S.push(l,r);}
  #undef ls
  #undef rs
  #undef mid
  #undef L
  #undef R
};
il void Solve()
{
  int n;cin>>n;
  ve<array<int,3>>e(n);
  ve<int>lsh{-inf,inf};lsh.reserve(n*3+2);
  for(auto&[o,l,r]:e) {
    cin>>o>>l>>r;
    if(o==1) ++l,lsh.pb(l-1),lsh.pb(l),lsh.pb(r);
  }
  sort(all(lsh)),lsh.erase(unique(all(lsh)),end(lsh));
  for(auto&[o,l,r]:e) if(o==1) {
    // [l,r)
    l=lower_bound(all(lsh),l)-begin(lsh);
    r=lower_bound(all(lsh),r)-begin(lsh);
  }
  else --l,--r;
  DS S(lsh.size(),n);
  for(auto&[o,l,r]:e) {
    if(o==1) {
      int i=S.push(l,r);
      S._M(l-1,i),S._M(r,i),S._M(i);
    }
    else cout<<(S._Q(l,r)?"YES\n":"NO\n");
  }
  return;
}
void main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int T=1;
  // cin>>T;
  for(;T--;) {
    Solve();
  }
}}main(){BK0717::main();}