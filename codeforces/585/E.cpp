// LUOGU_RID: 160089244
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using ld=__float128;
using uint=unsigned int;
using ull=unsigned long long;

//#define int long long
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x.size())

template<class T>inline void gmin(T&a,T b) { if(a>b) a=b; }
template<class T>inline void gmax(T& a,T b) { if(a<b) a=b; }
template <class T>int lwb(vector<T> &a,const T &b) { return (int)(lower_bound(all(a),b)-a.begin()); }
template <class T>int upb(vector<T> &a,const T &b) { return (int)(upper_bound(all(a),b)-a.begin()); }

template<class T1,class T2> istream &operator>>(istream &cin,pair<T1,T2> &a) { return cin>>a.first>>a.second; }
template<class T>istream &operator>>(istream &cin,vector<T>&a) { for(auto &x:a) cin>>x; return cin; }
template<class T1,class T2> ostream &operator<<(ostream &cout,const pair<T1,T2> &a) { return cout<<a.first<<' '<<a.second; }
template<class T1> ostream &operator<<(ostream &cout,const vector<T1> &a) { if(sz(a)==0) return cout; int f=0; for(auto&x:a) cout<<(f++?" ":"")<<x; return cout; }

#ifdef DEBUG
#include <algo/debug.h>
#else
#define debug(...) (void)114
#define debug_s() (void)114
#define assert(...) (void)114
#endif

const int maxn=5e5+10,N=1e7+10;

// const int mod=998244353;
// const int mod=1e9+7;

const int big=1e9;
const ll BIG=1e18;
template <typename T>
T inverse(T a,T m) {
    T u=0,v=1;
    while(a!=0) {
        T t=m/a;
        m-=t*a; swap(a,m);
        u-=t*v; swap(u,v);
    }
    assert(m==1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type=typename decay<decltype(T::value)>::type;

    constexpr Modular(): value() {}
    template <typename U>
    Modular(const U& x) {
        value=normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if(-mod()<=x&&x<mod()) v=static_cast<Type>(x);
        else v=static_cast<Type>(x%mod());
        if(v<0) v+=mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if((value+=other.value)>=mod()) value-=mod(); return *this; }
    Modular& operator-=(const Modular& other) { if((value-=other.value)<0) value+=mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this+=Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this-=Modular(other); }
    Modular& operator++() { return *this+=1; }
    Modular& operator--() { return *this-=1; }
    Modular operator++(int) { Modular result(*this); *this+=1; return result; }
    Modular operator--(int) { Modular result(*this); *this-=1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U=T>
    typename enable_if<is_same<typename Modular<U>::Type,int>::value,Modular>::type& operator*=(const Modular& rhs) {
        value=normalize(static_cast<int64_t>(value)*static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U=T>
    typename enable_if<is_same<typename Modular<U>::Type,long long>::value,Modular>::type& operator*=(const Modular& rhs) {
        long long q=static_cast<long long>(static_cast<long double>(value)*rhs.value/mod());
        value=normalize(value*rhs.value-q*mod());
        return *this;
    }
    template <typename U=T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value,Modular>::type& operator*=(const Modular& rhs) {
        value=normalize(value*rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this*=Modular(inverse(other.value,mod())); }

    friend const Type& abs(const Modular& x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs,const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs,const Modular<U>& rhs);

    template <typename V,typename U>
    friend V& operator>>(V& stream,Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs,const Modular<T>& rhs) { return lhs.value==rhs.value; }
template <typename T,typename U> bool operator==(const Modular<T>& lhs,U rhs) { return lhs==Modular<T>(rhs); }
template <typename T,typename U> bool operator==(U lhs,const Modular<T>& rhs) { return Modular<T>(lhs)==rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs,const Modular<T>& rhs) { return !(lhs==rhs); }
template <typename T,typename U> bool operator!=(const Modular<T>& lhs,U rhs) { return !(lhs==rhs); }
template <typename T,typename U> bool operator!=(U lhs,const Modular<T>& rhs) { return !(lhs==rhs); }

template <typename T> bool operator<(const Modular<T>& lhs,const Modular<T>& rhs) { return lhs.value<rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs,const Modular<T>& rhs) { return Modular<T>(lhs)+=rhs; }
template <typename T,typename U> Modular<T> operator+(const Modular<T>& lhs,U rhs) { return Modular<T>(lhs)+=rhs; }
template <typename T,typename U> Modular<T> operator+(U lhs,const Modular<T>& rhs) { return Modular<T>(lhs)+=rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs,const Modular<T>& rhs) { return Modular<T>(lhs)-=rhs; }
template <typename T,typename U> Modular<T> operator-(const Modular<T>& lhs,U rhs) { return Modular<T>(lhs)-=rhs; }
template <typename T,typename U> Modular<T> operator-(U lhs,const Modular<T>& rhs) { return Modular<T>(lhs)-=rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs,const Modular<T>& rhs) { return Modular<T>(lhs)*=rhs; }
template <typename T,typename U> Modular<T> operator*(const Modular<T>& lhs,U rhs) { return Modular<T>(lhs)*=rhs; }
template <typename T,typename U> Modular<T> operator*(U lhs,const Modular<T>& rhs) { return Modular<T>(lhs)*=rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs,const Modular<T>& rhs) { return Modular<T>(lhs)/=rhs; }
template <typename T,typename U> Modular<T> operator/(const Modular<T>& lhs,U rhs) { return Modular<T>(lhs)/=rhs; }
template <typename T,typename U> Modular<T> operator/(U lhs,const Modular<T>& rhs) { return Modular<T>(lhs)/=rhs; }

template<typename T,typename U>
Modular<T> power(const Modular<T>& a,const U& b) {
    assert(b>=0);
    Modular<T> x=a,res=1;
    U p=b;
    while(p>0) {
        if(p&1) res*=x;
        x*=x;
        p>>=1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number()==0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U,typename T>
U& operator<<(U& stream,const Modular<T>& number) {
    return stream<<number();
}

// U == std::istream? but done this way because of fastinput
template <typename U,typename T>
U& operator>>(U& stream,Modular<T>& number) {
    typename common_type<typename Modular<T>::Type,long long>::type x;
    stream>>x;
    number.value=Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md=1e9+7;
using Mint=Modular<std::integral_constant<decay<decltype(md)>::type,md>>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

int n,mx,p[N];
int mu[N];
Mint p2[maxn];
bitset<N>vis;
vector<int>prime;

signed main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cout<<fixed<<setprecision(15);
    cin>>n;
    p2[0]=1;
    for(int i=1,x; i<=n; i++) cin>>x,p[x]++,p2[i]=p2[i-1]*2,gmax(mx,x);
    mu[1]=1;
    for(int i=2; i<=mx; i++) {
        if(!vis[i]) prime.emplace_back(i),mu[i]=-1;
        if(!vis[i]) prime.pb(i),mu[i]=-1;
        for(auto& x:prime) {
            if(x*i>mx) break;
            vis[i*x]=1;
            if(i%x==0) {
                mu[i*x]=0;
                break;
            }
            mu[i*x]=-mu[i];
        }
    }
    Mint res=0;
    for(int i=1; i<=mx; i++) {
        int sum=0;
        for(int j=i; j<=mx; j+=i) sum+=p[j];
        res+=(-mu[i])*(p2[sum]-1)*(n-sum);
    }
    cout<<res<<'\n';
    return 0;
}