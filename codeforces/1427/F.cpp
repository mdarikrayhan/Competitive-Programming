//Shirasu Azusa 2024.5
#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
template<typename T,typename U>
T ceil(T x, U y) {return (x>0?(x+y-1)/y:x/y);}
template<typename T,typename U>
T floor(T x, U y) {return (x>0?x/y:(x-y+1)/y);}
template<class T,class S>
bool chmax(T &a,const S b) {return (a<b?a=b,1:0);}
template<class T,class S>
bool chmin(T &a,const S b) {return (a>b?a=b,1:0);}
int popcnt(int x) {return __builtin_popcount(x);}
int popcnt(ll x) {return __builtin_popcountll(x);}
int topbit(int x) {return (x==0?-1:31-__builtin_clz(x));}
int topbit(ll x) {return (x==0?-1:63-__builtin_clzll(x));}
int lowbit(int x) {return (x==0?-1:__builtin_ctz(x));}
int lowbit(ll x) {return (x==0?-1:__builtin_ctzll(x));}

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
int n,a[N],x[N][3],st[N],top,m;
vi e[N],ans;
queue<int> q[4];

void ins(int u) {
  if(e[u].size()) q[a[x[u][0]]&1].push(u);
  else q[(a[x[u][0]]&1)+2].push(u);
}
signed main() {
  n=read();
  rep(i,1,3*n) a[read()]=1;
  rep(i,1,6*n) {
    if(!top||a[x[st[top]][0]]!=a[i]) {
      ++m; e[st[top]].eb(m);
      x[m][0]=i; st[++top]=m;
    } else {
      if(!x[st[top]][1]) x[st[top]][1]=i;
      else x[st[top]][2]=i, --top;  
    }
  }
  for(int x:e[0]) ins(x);
  per(t,2*n,1) {
    if(q[t&1].size()) {
      int u=q[t&1].front(); q[t&1].pop();
      for(int v:e[u]) ins(v); ans.eb(u);
    } else {
      int u=q[(t&1)+2].front(); q[(t&1)+2].pop();
      ans.eb(u);
    }
  }
  reverse(ans.begin(),ans.end());
  for(int i:ans) {
    printf("%d %d %d\n",x[i][0],x[i][1],x[i][2]);
  }
  return 0;
}