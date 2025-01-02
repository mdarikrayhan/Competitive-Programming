#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
template<int mod>istream &operator>>(istream &is,static_modint<mod> &a){long long b;is>>b;a=b;return is;}
istream &operator>>(istream &is,modint &a){long long b;cin>>b;a=b;return is;}
#endif
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) static_cast<void>(0)
#define debugg(...) static_cast<void>(0)
#define esper(...) static_cast<void>(0)
template<typename T1,typename T2>ostream &operator<<(ostream &os,const pair<T1,T2>&p){os<<p.first<<' '<<p.second;return os;}
#endif
using ll=long long;
using ull=unsigned long long;
using P=pair<ll,ll>;
template<typename T>using minque=priority_queue<T,vector<T>,greater<T>>;
template<typename T>bool chmax(T &a,const T &b){return (a<b?(a=b,true):false);}
template<typename T>bool chmin(T &a,const T &b){return (a>b?(a=b,true):false);}
template<typename T1,typename T2>istream &operator>>(istream &is,pair<T1,T2>&p){is>>p.first>>p.second;return is;}
template<typename T>istream &operator>>(istream &is,vector<T> &a){for(auto &i:a)is>>i;return is;}
template<typename T1,typename T2>void operator++(pair<T1,T2>&a,int n){a.first++,a.second++;}
template<typename T1,typename T2>void operator--(pair<T1,T2>&a,int n){a.first--,a.second--;}
template<typename T>void operator++(vector<T>&a,int n){for(auto &i:a)i++;}
template<typename T>void operator--(vector<T>&a,int n){for(auto &i:a)i--;}
#define reps(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) reps(i,0,n)
#define all(x) x.begin(),x.end()
#define pcnt(x) __builtin_popcountll(x)
#define fin(x) return cout<<x<<'\n',static_cast<void>(0)
ll myceil(ll a,ll b){return (a+b-1)/b;}
template<typename T,size_t n,size_t id=0>
auto vec(const int (&d)[n],const T &init=T()){
  if constexpr (id<n)return vector(d[id],vec<T,n,id+1>(d,init));
  else return init;
}
void SOLVE();
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<fixed<<setprecision(16);
  #ifdef LOCAL
  clock_t start=clock();
  #endif
  int testcase=1;
  //cin>>testcase;
  for(int i=0;i<testcase;i++){
    SOLVE();
  }
  #ifdef LOCAL
  cerr<<"time:";
  cerr<<(clock()-start)/1000;
  cerr<<"ms\n";
  #endif
}
template<int m>
struct montgomery_modint{
private:
  using mint=montgomery_modint;
  using i32=int32_t;
  using u32=uint32_t;
  using u64=uint64_t;
  static constexpr u32 get_r(){
    u32 ret=m;
    for(u32 i=0;i<4;i++)ret*=2-m*ret;
    return ret;
  }
  static_assert(m>2);
  static_assert(m<(1<<30));
  static_assert(m&1);
  static constexpr u32 r1=get_r();
  static constexpr u32 r2=-u64(m)%m;
  u32 v;
  static constexpr u32 reduce(const u64 &a){
    return (a+u64(u32(a)*u32(-r1))*m)>>32;
  }
public:
  montgomery_modint():v(0){}
  montgomery_modint(ll a):v(reduce(u64(a%m+m)*r2)){}
  static mint raw(int a){
    mint ret;
    ret.v=reduce(u64(a)*r2);
    return ret;
  }
  u32 val()const{
    u32 ret=reduce(v);
    return ret>=m?ret-m:ret;
  }
  static constexpr int mod(){return m;}
  mint &operator+=(const mint &b){
    if(i32(v+=b.v-m*2)<0)v+=m*2;
    return *this;
  }
  mint &operator-=(const mint &b){
    if(i32(v-=b.v)<0)v+=m*2;
    return *this;
  }
  mint &operator*=(const mint &b){
    v=reduce(u64(v)*b.v);
    return *this;
  }
  mint &operator/=(const mint &b){
    *this*=b.inv();
    return *this;
  }
  mint operator+()const{return *this;}
  mint operator-()const{return mint()-*this;}
  friend mint operator+(const mint &a,const mint &b){return mint(a)+=b;}
  friend mint operator-(const mint &a,const mint &b){return mint(a)-=b;}
  friend mint operator*(const mint &a,const mint &b){return mint(a)*=b;}
  friend mint operator/(const mint &a,const mint &b){return mint(a)/=b;}
  friend bool operator==(const mint &a,const mint &b){return (a.v>=m?a.v-m:a.v)==(b.v>=m?b.v-m:b.v);}
  friend bool operator!=(const mint &a,const mint &b){return !(a==b);}
  mint pow(ll n)const{
    mint ret=1,a(*this);
    while(n){
      if(n&1)ret*=a;
      a*=a;
      n>>=1;
    }
    return ret;
  }
  inline mint inv()const{
    return pow(m-2);
  }
  friend istream &operator>>(istream &is,mint &b){
    ll a;
    is>>a;
    b=mint(a);
    return is;
  }
  friend ostream &operator<<(ostream &os,const mint &b){
    os<<b.val();
    return os;
  }
};
constexpr int primitive_root(int x){
  if(x==998244353)return 3;
  if(x==167772161)return 3;
  if(x==469762049)return 3;
  if(x==2)return 1;
  int x2=x;
  int p[20];
  int c=0;
  x--;
  for(int i=2;i*i<=x;i++){
    if(x%i==0){
      p[c++]=i;
      while(x%i==0)x/=i;
    }
  }
  if(x!=1)p[c++]=x;
  x=x2;
  auto powmod=[](ll a,int n,int mod)->int {
    ll ret=1;
    while(n){
      if(n&1)ret=(ret*a)%mod;
      a=(a*a)%mod;
      n>>=1;
    }
    return ret;
  };
  for(int g=2;;g++){
    bool ok=true;
    for(int i=0;i<c;i++)if(powmod(g,(x-1)/p[i],x)==1){
      ok=false;
      break;
    }
    if(ok)return g;
  }
}
constexpr int countr_zero(unsigned int n){
  int ret=0;
  while(!(n&(1<<ret)))ret++;
  return ret;
}
template<typename T>
struct ntt_root{
  static constexpr int rank2=countr_zero(T::mod()-1);
  int g=primitive_root(T::mod());
  array<T,rank2+1>root,invroot;
  array<T,max(0,rank2-1)>rate2,invrate2;
  array<T,max(0,rank2-2)>rate3,invrate3;
  ntt_root(){
    root[rank2]=T::raw(g).pow((T::mod())>>rank2);
    invroot[rank2]=root[rank2].inv();
    for(int i=rank2-1;i>=0;i--){
      root[i]=root[i+1]*root[i+1];
      invroot[i]=invroot[i+1]*invroot[i+1];
    }
    {
      T prod=1,invprod=1;
      rep(i,rank2-1){
        rate2[i]=root[i+2]*prod;
        invrate2[i]=invroot[i+2]*invprod;
        prod*=invroot[i+2];
        invprod*=root[i+2];
      }
    }
    {
      T prod=1,invprod=1;
      rep(i,rank2-2){
        rate3[i]=root[i+3]*prod;
        invrate3[i]=invroot[i+3]*invprod;
        prod*=invroot[i+3];
        invprod*=root[i+3];
      }
    }
  }
};
template<typename T>
void dft(vector<T>&a){
  int n=a.size();
  static const ntt_root<T> r;
  int h=countr_zero(n);
  ull mod2=(ull)T::mod()*T::mod();
  int len=0;
  while(len<h){
    if(h-len==1){
      T rot=1;
      rep(s,1<<len){
        int of=s*2;
        T u=a[of],v=a[of+1]*rot;
        a[of]=u+v;
        a[of+1]=u-v;
        if(s+1!=1<<len)rot*=r.rate2[__builtin_ctz(~(unsigned int)s)];
      }
      len++;
    }
    else{
      int p=1<<(h-len-2);
      T rot=1,imag=r.root[2];
      rep(s,1<<len){
        T rot2=rot*rot,rot3=rot*rot2;
        int of=s<<(h-len);
        rep(i,p){
          ull a0=a[i+of].val(),a1=(ull)a[i+of+p].val()*rot.val(),a2=(ull)a[i+of+p*2].val()*rot2.val(),a3=(ull)a[i+of+p*3].val()*rot3.val();
          ull m=(ull)T(a1+mod2-a3).val()*imag.val();
          ull k=mod2-a2;
          a[i+of]=a0+a2+a1+a3;
          a[i+of+p]=a0+a2+(mod2*2-a1-a3);
          a[i+of+p*2]=a0+k+m;
          a[i+of+p*3]=a0+k+(mod2-m);
        }
        if(s+1!=1<<len)rot*=r.rate3[__builtin_ctz(~(unsigned int)s)];
      }
      len+=2;
    }
  }
}
template<typename T>
void idft(vector<T>&a){
  int n=a.size();
  static const ntt_root<T> r;
  int h=countr_zero(n);
  ull mod2=(ull)T::mod()*T::mod();
  int len=h;
  while(len){
    if(len==1){
      int p=1<<(h-1);
      T rot=1;
      rep(i,p){
        T u=a[i],v=a[i+p];
        a[i]=u+v;
        a[i+p]=(ull)(u.val()-v.val()+T::mod())*rot.val();
      }
      len--;
    }
    else{
      int p=1<<(h-len);
      T rot=1,imag=r.invroot[2];
      rep(s,1<<(len-2)){
        T rot2=rot*rot,rot3=rot*rot2;
        int of=s<<(h-len+2);
        rep(i,p){
          ull a0=a[i+of].val(),a1=a[i+of+p].val(),a2=a[i+of+p*2].val(),a3=a[i+of+p*3].val();
          ull k=T((T::mod()+a2-a3)*imag.val()).val();
          a[i+of]=a0+a1+a2+a3;
          a[i+of+p]=(a0+T::mod()-a1+k)*rot.val();
          a[i+of+p*2]=(a0+a1+T::mod()*2-a2-a3)*rot2.val();
          a[i+of+p*3]=(a0+T::mod()*2-a1-k)*rot3.val();
        }
        if(s+1!=1<<(len-2))rot*=r.invrate3[countr_zero(~(unsigned int)s)];
      }
      len-=2;
    }
  }
}
template<typename T>
vector<T>ntt_convolution(vector<T> a,vector<T> b){
  int n=a.size(),m=b.size(),s=n+m-1;
  if(min(n,m)<60){
    vector<T>ret(s,0);
    if(n<m)rep(i,m)rep(j,n)ret[i+j]+=a[j]*b[i];
    else rep(i,n)rep(j,m)ret[i+j]+=a[i]*b[j];
    return ret;
  }
  int z=1;
  while(z<=s)z*=2;
  a.resize(z,0);
  b.resize(z,0);
  dft(a),dft(b);
  vector<T>c(z);
  rep(i,z)c[i]=a[i]*b[i];
  idft(c);
  T g=T::raw(z).inv();
  rep(i,s)c[i]*=g;
  return {c.begin(),c.begin()+s};
}
int garner(vector<pair<int,int>>r,int mod){
  r.emplace_back(0,mod);
  vector<ll>a(r.size(),1),b(r.size(),0);
  auto invmod=[](ll a,ll mod)->ll {
    ll n=mod-2;
    ll ret=1;
    while(n){
      if(n&1)ret=(ret*a)%mod;
      a=(a*a)%mod;
      n>>=1;
    }
    return ret;
  };
  rep(i,r.size()-1){
    ll v=(r[i].first-b[i])*invmod(a[i],r[i].second)%r[i].second;
    if(v<0)v+=r[i].second;
    reps(j,i+1,r.size()){
      b[j]+=a[j]*v;
      b[j]%=r[j].second;
      a[j]*=r[i].second;
      a[j]%=r[j].second;
    }
  }
  return b[r.size()-1];
}
template<typename T>
vector<T>anymod_convolution(const vector<T>&a,const vector<T>&b){
  if(a.empty()||b.empty())return vector<T>{};
  if(min(a.size(),b.size())<60){
    vector<T>ret(a.size()+b.size()-1,0);
    rep(i,a.size())rep(j,b.size())ret[i+j]+=a[i]*b[j];
    return ret;
  }
  using mint1=montgomery_modint<167772161>;
  using mint2=montgomery_modint<469762049>;
  using mint3=montgomery_modint<998244353>;
  vector<mint1>a1(a.size()),b1(b.size());
  vector<mint2>a2(a.size()),b2(b.size());
  vector<mint3>a3(a.size()),b3(b.size());
  rep(i,a.size()){
    a1[i]=a[i].val();
    a2[i]=a[i].val();
    a3[i]=a[i].val();
  }
  rep(i,b.size()){
    b1[i]=b[i].val();
    b2[i]=b[i].val();
    b3[i]=b[i].val();
  }
  a1=ntt_convolution(a1,b1),a2=ntt_convolution(a2,b2),a3=ntt_convolution(a3,b3);
  vector<T>ret(a.size()+b.size()-1);
  rep(i,ret.size()){
    vector<pair<int,int>>r(3);
    r[0].first=a1[i].val(),r[0].second=mint1::mod();
    r[1].first=a2[i].val(),r[1].second=mint2::mod();
    r[2].first=a3[i].val(),r[2].second=mint3::mod();
    ret[i]=garner(r,T::mod());
  }
  return ret;
}
template<typename T>
vector<T> fps_inv(const vector<T> &a,int deg=-1){
  int n=a.size();
  if(deg==-1)deg=n;
  assert(a[0]!=T(0));
  vector<T> ret(deg);
  ret[0]=a[0].inv();
  for(int m=1;m<deg;m<<=1){
    vector<T> f(a.begin(),a.begin()+min(n,m*2));
    if(f.size()<m*2)f.resize(m*2,0);
    vector<T> g(ret);
    f.resize(m*2);
    dft(f);
    g.resize(m*2);
    dft(g);
    rep(i,m*2)f[i]*=g[i];
    idft(f);
    T inv=T::raw(m*2).inv();
    rep(i,m)f[i]=0;
    reps(i,m,m*2)f[i]*=inv;
    dft(f);
    rep(i,m*2)f[i]*=g[i];
    idft(f);
    rep(i,m*2)f[i]*=inv;
    reps(i,m,min(deg,m*2))ret[i]-=f[i];
  }
  return ret;
}
template<typename T>
vector<T> fps_diff(const vector<T>&a){
  int n=a.size();
  vector<T>b(max(0,n-1));
  reps(i,1,n)b[i-1]=a[i]*i;
  return b;
}
template<typename T>
vector<T> fps_integral(const vector<T>&a){
  int n=a.size();
  vector<T>b(n+1);
  b[0]=0;
  if(n)b[1]=1;
  reps(i,2,n+1)b[i]=-b[T::mod()%i]*(T::mod()/i);
  rep(i,n)b[i+1]*=a[i];
  return b;
}
template<typename T>
vector<T> fps_log(const vector<T>&a,int deg=-1){
  int n=a.size();
  if(deg==-1)deg=n;
  vector<T>b=fps_integral(ntt_convolution(fps_diff(a),fps_inv(a,deg)));
  return {b.begin(),b.begin()+deg};
}
template<typename T>
vector<T> fps_exp(const vector<T>&a,int deg=-1){
  assert(a.empty()||a[0]==0);
  int n=a.size();
  if(deg==-1)deg=n;
  vector<T>b{1};
  for(int m=1;m<deg;m*=2){
    vector<T>nxt=fps_log(b,m*2);
    rep(i,m*2)nxt[i]*=-1;
    rep(i,min(n,m*2))nxt[i]+=a[i];
    nxt[0]++;
    b=ntt_convolution(b,nxt);
    b.resize(m*2);
  }
  return {b.begin(),b.begin()+deg};
}
template<typename T>
vector<T> fps_pow(vector<T> a,ll k,int deg=-1){
  int n=a.size();
  if(deg==-1)deg=n;
  if(k==0){
    vector<T>ret(deg,0);
    ret[0]=1;
    return ret;
  }
  int of=0;
  while(a[of]==0&&of!=n)of++;
  if(of==n)return vector<T>(deg,0);
  if(of!=0&&k>=deg)return vector<T>(deg,0);
  if(of*k>=deg)return vector<T>(deg,0);
  a.erase(a.begin(),a.begin()+of);
  n=a.size();
  T a0=a[0];
  T inv=a[0].inv();
  rep(i,n)a[i]*=inv;
  vector<T>lg=fps_log(a,deg);
  rep(i,deg)lg[i]*=k;
  vector<T>ep=fps_exp(lg,deg);
  T pw=a0.pow(k);
  rep(i,deg)ep[i]*=pw;
  vector<T>ret(deg,0);
  reps(i,of*k,deg)ret[i]=ep[i-of*k];
  return ret;
}
template<typename T>
vector<T> fps_pow_sparse(const vector<T>&a,ll k,int deg=-1){
  int n=a.size();
  if(deg==-1)deg=n;
  vector<pair<int,T>>b;
  rep(i,n)if(a[i]!=0)b.emplace_back(i,a[i]);
  if(b.empty()){
    vector<T>ret(deg,0);
    if(k==0)ret[0]=1;
    return ret;
  }
  int of=b[0].first;
  T b0=b[0].second,inv=b0.inv();
  for(auto &i:b){
    i.first-=of;
    i.second*=inv;
  }
  b0=b0.pow(k);
  vector<T>ret(deg,0);
  ret[0]=1;
  rep(i,deg-1){
    T cu=0;
    for(auto [j,c]:b){
      if(i-j+1<0)continue;
      if(j==0)continue;
      cu-=c*ret[i-j+1]*(i-j+1);
      cu+=ret[i-j+1]*k*j*c;
    }
    ret[i+1]=cu/(i+1);
  }
  if(of){
    if(k>=deg||of*k>=deg)ret.assign(deg,0);
    else{
      ret.insert(ret.begin(),of*k,0);
      ret.resize(deg);
    }
  }
  for(auto &i:ret)i*=b0;
  return ret;
}
template<typename T>
vector<T> fps_div_sparse(vector<T> a,const vector<T>&b,int deg=-1){
  int n=a.size(),m=b.size();
  if(deg==-1)deg=n;
  a.resize(deg,0);
  assert(b[0]!=0);
  vector<pair<int,T>>c;
  reps(i,1,m)if(b[i]!=0)c.emplace_back(i,b[i]);
  T v=b[0].inv();
  rep(i,deg){
    for(auto [j,e]:c){
      if(j>i)break;
      a[i]-=a[i-j]*e;
    }
    a[i]*=v;
  }
  return a;
}
template<typename T>
inline vector<T> fps_inv_sparse(const vector<T>&a,int deg=-1){
  return fps_div_sparse({1},a,(deg==-1?a.size():deg));
}
template<typename T>
vector<T>fps_fode_sparse(const vector<T>&a,const vector<T>&b){
  assert(a.size()==b.size());
  assert(a[0]==1);
  int n=a.size();
  vector<pair<int,T>>c,d;
  reps(i,1,n)if(a[i]!=0)c.emplace_back(i,a[i]);
  rep(i,n)if(b[i]!=0)d.emplace_back(i,b[i]);
  vector<T>f(n),df(n-1);
  f[0]=1;
  vector<T>inv(n);
  rep(i,n-1){
    T v=0;
    for(auto [j,x]:c){
      if(j>i)break;
      v+=x*df[i-j];
    }
    for(auto [j,x]:d){
      if(j>i)break;
      v+=x*f[i-j];
    }
    df[i]=-v;
    if(i==0)inv[1]=1;
    else inv[i+1]=-inv[T::mod()%(i+1)]*(T::mod()/(i+1));
    f[i+1]=df[i]*inv[i+1];
  }
  return f;
}
template<typename T>
vector<T> fps_pow_sparse(const vector<T>&a,const vector<T>&b,ll k,ll l,int deg=-1){
  int n=a.size(),m=b.size();
  if(deg==-1)deg=n;
  assert(a[0]==1);
  vector<pair<int,T>>c,d;
  rep(i,n)if(a[i]!=0)c.emplace_back(i,a[i]);
  rep(i,m)if(b[i]!=0)d.emplace_back(i,b[i]);
  vector<T>f(deg,0),g(deg,0);
  for(auto [i,x]:c){
    for(auto [j,y]:d){
      if(i+j>=deg+1)continue;
      T z=x*y;
      if(i+j<deg)f[i+j]+=z;
      if(0<i+j&&i+j<=deg)g[i+j-1]-=z*(T(i)*k+T(j)*l);
    }
  }
  return fps_fode_sparse(f,g);
}
template<typename T>
T bostan_mori(vector<T> p,vector<T> q,ll k){
  int z=1;
  int n=p.size(),m=q.size();
  while(z<m*2)z*=2;
  p.resize(z,0),q.resize(z,0);
  n=m-1;
  while(k){
    dft(p),dft(q);
    for(int i=0;i<z;i+=2)p[i]*=q[i+1];
    for(int i=1;i<z;i+=2)p[i]*=q[i-1];
    vector<T>v(z/2);
    rep(i,z/2)v[i]=q[i*2]*q[i*2+1];
    idft(p),idft(v);
    T inv=T::raw(z).inv(),inv2=inv*2;
    rep(i,z/2)v[i]*=inv2;
    vector<T>u(n);
    if(k&1)rep(i,n)u[i]=p[i*2+1]*inv;
    else rep(i,n)u[i]=p[i*2]*inv;
    u.resize(z,0),v.resize(z,0);
    swap(p,u),swap(q,v);
    k>>=1;
  }
  return p[0];
}
template<typename T>
vector<T> berlekamp_massey(const vector<T>&s){
  const int n=s.size();
  vector<T>b,c;
  b.reserve(n+1),c.reserve(n+1);
  b.emplace_back(1),c.emplace_back(1);
  T y=1;
  reps(i,1,n+1){
    int l=c.size(),m=b.size();
    T x=0;
    rep(j,l)x+=c[j]*s[i-l+j];
    b.emplace_back(0);
    ++m;
    if(x==0)continue;
    T f=x/y;
    if(l<m){
      auto c2=c;
      c.insert(c.begin(),m-l,0);
      rep(j,m)c[m-1-j]-=f*b[m-1-j];
      b=c2;
      y=x;
    }
    else{
      rep(j,m)c[l-1-j]-=f*b[m-1-j];
    }
  }
  reverse(all(c));
  return c;
}
template<typename T>
T kth_term(vector<T>p,ll k){
  vector<T>q=berlekamp_massey(p);
  if(T::mod()==998244353){
    p=ntt_convolution(p,q);
    p.resize(q.size()-1);
    return bostan_mori(p,q,k);
  }
  auto convolution_naive=[](vector<T>&x,const vector<T>&y)->void {
    vector<T>temp(x.size()+y.size()-1,0);
    rep(i,x.size())rep(j,y.size())temp[i+j]+=x[i]*y[j];
    swap(x,temp);
  };
  convolution_naive(p,q);
  int n=q.size();
  p.resize(n-1);
  vector<T>mq(n);
  while(k){
    rep(i,n)mq[i]=q[i]*(i&1?-1:1);
    convolution_naive(p,mq);
    convolution_naive(q,mq);
    vector<T>u(n-1),v(n);
    if(k&1)rep(i,n-1)u[i]=p[i*2+1];
    else rep(i,n-1)u[i]=p[i*2];
    rep(i,n)v[i]=q[i*2];
    swap(p,u),swap(q,v);
    k>>=1;
  }
  if(p.empty())return 0;
  else return p[0];
}
template<typename T>
vector<T>fps_polynominal_talor_shift(vector<T>a,T c,int deg=-1){
  if(deg==-1)deg=a.size();
  else if(deg<a.size())a.resize(deg);
  vector<T>fact(deg),factinv(deg),inv(deg);
  fact[0]=fact[1]=factinv[0]=factinv[1]=inv[1]=1;
  reps(i,2,deg){
    fact[i]=fact[i-1]*i;
    inv[i]=-inv[T::mod()%i]*(T::mod()/i);
    factinv[i]=factinv[i-1]*inv[i];
  }
  vector<T>f(deg,0),g(deg,0);
  T now=1;
  rep(i,a.size()){
    f[i]=a[i]*fact[i];
    g[deg-i-1]=now*factinv[i];
    now*=c;
  }
  f=ntt_convolution(f,g);
  vector<T>ret(deg);
  rep(i,deg)ret[i]=f[i+deg-1]*factinv[i];
  return ret;
}
template<typename T>
vector<T>fps_middle_product(vector<T>a,vector<T>b){
  assert(a.size()>=b.size());
  reverse(all(b));
  int n=a.size(),m=b.size();
  int z=1;
  while(z<n)z<<=1;
  a.resize(z,0),b.resize(z,0);
  dft(a),dft(b);
  rep(i,z)a[i]*=b[i];
  idft(a);
  T invz=T(z).inv();
  reps(i,m-1,n)a[i]*=invz;
  return vector<T>(a.begin()+m-1,a.begin()+n);
}
template<typename T>
vector<vector<T>>convolution2d(vector<vector<T>>a,vector<vector<T>>b){
  int x=a.size()+b.size()-1,y=a[0].size()+b[0].size()-1;
  vector<T>f(a.size()*y),g(b.size()*y);
  rep(i,a.size())rep(j,a[i].size())f[i*y+j]=a[i][j];
  rep(i,b.size())rep(j,b[i].size())g[i*y+j]=b[i][j];
  auto c=ntt_convolution(f,g);
  vector<vector<T>>ret(x,vector<T>(y));
  rep(i,x)rep(j,y)ret[i][j]=c[i*y+j];
  return ret;
}
template<typename T>
vector<T>fps_pows(vector<T>f,vector<T>g,int n){
  int sz=f.size();
  vector<vector<T>>p(sz,vector<T>(2)),q(sz,vector<T>(2));
  q[0][0]=1;
  rep(i,min<int>(g.size(),sz))p[i][0]=g[i];
  rep(i,sz)q[i][1]=-f[i];
  int k=sz-1;
  while(k){
    int x=p.size(),y=p[0].size();
    vector<vector<T>>mq(q);
    for(int i=1;i<x;i+=2)rep(j,y)mq[i][j]=-mq[i][j];
    vector<vector<T>>f=convolution2d(p,mq);
    vector<vector<T>>g=convolution2d(q,mq);
    p.resize(k/2+1);
    q.resize(k/2+1);
    if(k&1)rep(i,p.size())p[i]=f[i*2+1];
    else rep(i,p.size())p[i]=f[i*2];
    rep(i,q.size())q[i]=g[i*2];
    rep(i,p.size())if(p[i].size()>n+1)p[i].resize(n+1);
    rep(i,q.size())if(q[i].size()>n+1)q[i].resize(n+1);
    k>>=1;
  }
  vector<T>f2(p[0]),g2(q[0]);
  vector<T>ret=ntt_convolution(f2,fps_inv(g2));
  ret.resize(n+1);
  return ret;
}
template<typename T>
vector<T>fps_composition(vector<T>f,vector<T>g,int deg=-1){
  if(deg==-1)deg=f.size();
  f.resize(deg,0),g.resize(deg,0);
  T c=g[0];
  g[0]=0;
  f=fps_polynominal_talor_shift(f,c);
  auto dfs=[&](auto self,vector<vector<T>>p)->vector<vector<T>> {
    int h=p.size(),w=p[0].size();
    if(h==1){
      vector<vector<T>>ret(h,vector<T>(w));
      rep(i,f.size())ret[0][i]=f[i];
      return ret;
    }
    vector<vector<T>>p2(p);
    rep(i,h)if(i&1)rep(j,w)p2[i][j]=-p2[i][j];
    vector<vector<T>>p3=convolution2d(p,p2);
    int h2=(h+1)/2;
    rep(i,h2)p3[i]=p3[i*2];
    p3.resize(h2);
    vector<vector<T>>q=self(self,p3);
    vector<T>a(2*h*(2*w-1)-1);
    rep(i,q.size())rep(j,q[i].size()){
      a[(i*2+!(h&1))*(w*2-1)+j]=q[i][j];
    }
    vector<T>b(2*h*(2*w-1));
    rep(i,h)rep(j,w){
      b[i*(2*w-1)+j]=p2[i][j];
    }
    reverse(all(b));
    a=ntt_convolution(a,b);
    a.erase(a.begin(),a.begin()+b.size()-1);
    a.resize(h*(2*w-1));
    vector<vector<T>>ret(h,vector<T>(w));
    rep(i,h)rep(j,w){
      ret[i][j]=a[i*(2*w-1)+j];
    }
    return ret;
  };
  vector<vector<T>>g2(deg,vector<T>(2,0));
  g2[0][0]=1;
  rep(i,deg)g2[i][1]=-g[i];
  auto p=dfs(dfs,g2);
  vector<T>ret(deg);
  rep(i,deg)ret[i]=p[i][0];
  reverse(all(ret));
  return ret;
}
template<typename T>
vector<T>fps_divmod(vector<T>f,vector<T>g){
  if(f.empty())return f;
  int n=f.size(),m=g.size();
  vector<T>r(f);
  reverse(all(f)),reverse(all(g));
  vector<T>q=ntt_convolution(f,fps_inv(g,n));
  q.resize(max(0,n-m+1));
  auto p=ntt_convolution(g,q);
  reverse(all(p));
  rep(i,min<int>(p.size(),m))r[i]-=p[i];
  r.resize(m-1);
  while(!r.empty()&&r.back().val()==0)r.pop_back();
  return r;
}
template<typename T>
vector<T> fps_mpeval(vector<T>f,vector<T>x){
  int z=1;
  while(z<x.size())z<<=1;
  vector<vector<T>>poly(z*2);
  rep(i,x.size())poly[i+z]={1,-x[i]};
  reps(i,x.size(),z)poly[i+z]={1};
  for(int i=z-1;i>=1;i--)poly[i]=ntt_convolution(poly[i*2],poly[i*2+1]);
  vector<vector<T>>div(z*2);
  div[0]=move(f);
  reverse(all(div[0]));
  reps(i,1,z+x.size()){
    if(div[i>>1].size()<poly[i].size()){
      div[i]=div[i>>1];
      continue;
    }
    div[i]={div[i>>1].end()-poly[i].size()+1,div[i>>1].end()};
    vector<T>q=ntt_convolution(div[i>>1],fps_inv(poly[i],div[i>>1].size()));
    q.resize(div[i>>1].size()-poly[i].size()+1);
    vector<T>p=ntt_convolution(q,poly[i]);
    rep(j,div[i].size())div[i][j]-=p[p.size()-div[i].size()+j];
  }
  vector<T>ret(x.size());
  rep(i,x.size())ret[i]=div[i+z][0];
  return ret;
}
template<typename T>
vector<T>fps_mpeval(vector<T>f,T a,T r,int m){
  int n=f.size();
  auto fx=[&](T x)->T {
    T pwx=1,ret=0;
    rep(i,n){
      ret+=f[i]*pwx;
      pwx*=x;
    }
    return ret;
  };
  if(r==0){
    vector<T>ret(m);
    ret[0]=fx(a);
    reps(i,1,m)ret[i]=f[0];
    return ret;
  }
  if(min(n,m)<60){
    vector<T>ret(m);
    T now=a;
    rep(i,m){
      ret[i]=fx(now);
      now*=r;
    }
    return ret;
  }
  T pwa=1;
  rep(i,n){
    f[i]*=pwa;
    pwa*=a;
  }
  auto calc=[](T r,int m)->vector<T> {
    vector<T>ret(m);
    T pw=1;
    ret[0]=1;
    reps(i,1,m){
      ret[i]=ret[i-1]*pw;
      pw*=r;
    }
    return ret;
  };
  vector<T>g=calc(r.inv(),max(n,m));
  rep(i,n)f[i]*=g[i];
  f=fps_middle_product(calc(r,n+m-1),f);
  rep(i,m)f[i]*=g[i];
  return f;
}
using mint=montgomery_modint<998244353>;
void SOLVE(){
  int n,m;
  cin>>n>>m;
  vector<mint>f(m+1,0);
  rep(i,n){
    int a;
    cin>>a;
    if(a<=m)f[a]=1;
  }
  vector<mint>g{0};
  while(g.size()<=m){
    vector<mint>g2(g.size()*2);
    rep(i,g.size())g2[i]=g[i];
    vector<mint>p(g2.size()),q(g2.size());
    {
      vector<mint>g1(g);
      g1[0]+=1;
      g1=ntt_convolution(f,ntt_convolution(g1,g1));
      rep(i,g2.size())p[i]+=g1[i];
      rep(i,g.size())p[i]-=g[i];
    }
    {
      vector<mint>g1(g.size());
      rep(i,g.size())g1[i]=2*g[i];
      g1[0]+=2;
      g1=ntt_convolution(f,g1);
      rep(i,g1.size())if(i<q.size())q[i]+=g1[i];
      q[0]-=1;
    }
    p=ntt_convolution(p,fps_inv(q));
    rep(i,p.size())if(i<g2.size())g2[i]-=p[i];
    swap(g,g2);
  }
  reps(i,1,m+1)cout<<g[i].val()<<endl;
}