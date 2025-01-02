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

int n,k,q,mod,inv2;

int ksm(int x,int y,int r=1) {
  for(;y;y>>=1,x=x*x%mod) if(y&1) r=r*x%mod;
  return r;
}
int val(int i,int j) {
  int res=0;
  res=(mod+1-res)%mod;
  return res*ksm(i+j,mod-2)%mod;
}

signed main() {
  n=read(), k=read()-1, mod=read(), inv2=(mod+1)/2; chmin(k,20);
  int p=n>>k, r1=0, r2=0, r12=0;
  if(!p) return puts("0"), 0;
  rep(i,2,p*2) r1=(r1+ksm(i,mod-2)*min(i-1,2*p+1-i))%mod;
  rep(i,2,p*2+1) r12=(r12+ksm(i,mod-2)*min(i-1,2*p+2-i))%mod;
  rep(i,2,p*2+2) r2=(r2+ksm(i,mod-2)*min(i-1,2*p+3-i))%mod;
  int c2=n%(1<<k), c1=(1<<k)-c2;
  int c11=c1*(c1-1)%mod*inv2%mod, c12=c1*c2%mod, c22=c2*(c2-1)%mod*inv2%mod;
  int sum=(c11*r1%mod+c12*r12%mod+c22*r2%mod)%mod;
  int res=n*(n-1)%mod*ksm(4,mod-2)%mod;
  printf("%lld\n",(res-sum+mod)%mod);
  return 0;
}