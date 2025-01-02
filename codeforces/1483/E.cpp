//Shirasu Azusa 2024.4
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

int cur,cnt,lim=1e14;
int qry(int x) {
  if(x>lim) return 0;
  cnt++; if(cnt>105) assert(0);
  printf("? %lld\n",x); fflush(stdout);
  static char res[10]; scanf("%s",res);
  if(res[0]=='L') return cur+=x, 1;
  else if(res[1]=='r') return cur-=x, 0;
  else return exit(0), 0;
}
void repo(int x) {
  printf("! %lld\n",x);
}
void work() {
  cur=1; cnt=0; int x=2;
  if(!qry(1)) {repo(0); return;}
  for(;qry(x);x<<=1);
  int L=x/2, R=x;
  while(L<R-1) {
    while(cur<R) qry(L);
    ld e=1.*cur/(L*__lg(R-L)), p=0;
    if(e>1) p=0.5;
    else p=0.3+0.2*e;
    int k=L+max(1ll,(int)(p*(R-L)));
    if(qry(k)) L=k;
    else R=k;
  }
  repo(L);
}

signed main() {
  int T=read();
  while(T--) work();
  return 0;
}