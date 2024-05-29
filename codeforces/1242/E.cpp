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

#define int long long
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

const int N=3e5+5;
int n,tot,cur,st[N];
pii a[N];
vi p[N];
deque<int> q;

signed main() {
  n=read();
  rep(i,1,n) a[i].fi=read(), a[i].se=i;
  sort(a+1,a+n+1,greater<pii>());
  tot=cur=a[1].fi;
  rep(i,1,tot) p[a[1].se].eb(i), q.push_back(i);
  rep(i,2,n) {
    int y=a[i].fi, P=a[i+1].fi, cur=q.size(), x=cur;
    int z=x-y+2+2*(x==y);
    if(z<P) z+=(P-z+1)/2*2;
    int u=a[i].se, a=(x+y-z)/2, c=y-a;
    //cout<<"II "<<z<<endl;
    if(a==2&&y==3) {
      p[u].eb(q.front()); q.pop_front();
      p[u].eb(q.front()), p[u].eb(q.back());
    } else {
      p[u].eb(q.front());
      rep(j,2,a) p[u].eb(q.back()), q.pop_back();
      p[u].eb(q.back());
      rep(j,2,c) p[u].eb(++tot), q.push_back(tot);
    }
  }
  printf("%lld\n",tot);
  rep(i,1,n) {
    for(int x:p[i]) printf("%lld ",x); puts("");
  }
  return 0;
}