//Shirasu Azusa 2024.5
#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
template<class T,class S>
bool chmax(T &a,const S b) {return (a<b?a=b,1:0);}
template<class T,class S>
bool chmin(T &a,const S b) {return (a>b?a=b,1:0);}
int popcnt(int x) {return __builtin_popcount(x);}
int popcnt(ll x)  {return __builtin_popcountll(x);}
int topbit(int x) {return (x==0?-1:31-__builtin_clz(x));}
int topbit(ll x)  {return (x==0?-1:63-__builtin_clzll(x));}
int lowbit(int x) {return (x==0?-1:__builtin_ctz(x));}
int lowbit(ll x)  {return (x==0?-1:__builtin_ctzll(x));}

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef tuple<int,int,int> tiii;
int read() {
  int x=0,w=1; char c=getchar(); 
  while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
  while(isdigit(c)) {x=x*10+(c-'0'); c=getchar();} 
  return x*w;
}

const int N=2005;
int n,m,q,f[N];
bitset<N> a[N],b[N];
set<pii> st; set<int> pr;

void qry(int x,int y) {
  assert(x&&y);
  bool fl=((a[x]&a[y])!=a[x]);
  if(pr.find(x)!=pr.end()) pr.erase(x);
  if(fl) pr.insert(x);
}

signed main() {
  n=read(), m=read(), q=read();
  if(n==1||m==1) {rep(j,1,q) puts("-1"); return 0;}
  rep(i,1,n) st.insert(pii(f[i],i));
  pii ans(-1,-1);
  rep(i,1,m) b[i]=b[i-1], b[i].set(i);
  rep(i,1,q) {
    int x=read(), l=read(), r=read();
    if(ans.fi==x||ans.se==x) ans=pii(-1,-1);
    auto it=st.lower_bound(pii(f[x],x));
    if(it!=st.begin()&&next(it)!=st.end()) {
      qry((*prev(it)).se,(*next(it)).se);
    } else if(next(it)==st.end()) {
      int p=(*prev(it)).se;
      if(pr.find(p)!=pr.end()) pr.erase(p);
    }
    st.erase(pii(f[x],x));
    if(pr.find(x)!=pr.end()) pr.erase(x);
    a[x]=a[x]^b[r]^b[l-1], f[x]=a[x].count();
    st.insert(pii(f[x],x));
    it=st.find(pii(f[x],x));
    if(it!=st.begin()) qry((*prev(it)).se,x);
    if(next(it)!=st.end()) qry(x,(*next(it)).se);
    if(pr.size()==0) puts("-1");
    else {
      int u=*pr.begin(), v=(*next(st.find(pii(f[u],u)))).se;
      if(u>v) swap(u,v);
      int l=(a[u]&~a[v])._Find_first();
      int r=(a[v]&~a[u])._Find_first();
      if(l>r) swap(l,r);
      printf("%d %d %d %d\n",u,l,v,r);
    }
  }
  return 0;
}