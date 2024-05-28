// LUOGU_RID: 159194856
#include <bits/stdc++.h>

using namespace std;

namespace sk {
    // modint: https://www.cnblogs.com/hzy1/p/16344746.html
    // Edited by Starrykiller.
    using i64=long long;
    int inverse(int a, int m) { int r=1;
        while (a>1) { int t=m/a; r=i64(r)*(m-t)%m; a=m-t*a; }
        return r;
    }
};

namespace sk {
        
    template<int mod>
    struct static_modint { 
        int x;
        static_modint(i64 x) : x(normal(x%mod)) {}
        static_modint(): x(0) {}
        int normal(int x) { 
            if (x>=mod) x-=mod;
            return x+((x>>31)&mod); 
        }
        int val() const { return x; }
        static_modint inv() const { assert(x!=0); return static_modint(inverse(x, mod)); }
        static_modint pow(int x) const { assert(x>=0); static_modint a=*this, res=1;
            while (x) { if (x&1) res*=a; a*=a; x>>=1; } return res; }
        static_modint operator-() const { return static_modint(mod-x); }
        static_modint& operator+=(const static_modint &rhs) { x=normal(x+rhs.x); return *this; }
        static_modint& operator-=(const static_modint &rhs) { x=normal(x-rhs.x); return *this; }
        static_modint& operator++() { return (*this)+=1; }
        static_modint& operator--() { return (*this)-=1; }
        static_modint& operator*=(const static_modint &rhs) { x=i64(x)*rhs.x%mod; return *this; }
        static_modint& operator/=(const static_modint &rhs) { return *this *= rhs.inv(); }
        friend static_modint operator+(const static_modint &lhs, const static_modint &rhs) { auto res=lhs; res+=rhs; return res; }
        friend static_modint operator-(const static_modint &lhs, const static_modint &rhs) { auto res=lhs; res-=rhs; return res; }
        friend static_modint operator*(const static_modint &lhs, const static_modint &rhs) { auto res=lhs; res*=rhs; return res; }
        friend static_modint operator/(const static_modint &lhs, const static_modint &rhs) { auto res=lhs; res/=rhs; return res; }
        friend static_modint operator++(static_modint &x, int) { auto tmp=x; x+=1; return tmp; }
        friend static_modint operator--(static_modint &x, int) { auto tmp=x; x-=1; return tmp; }
        friend std::istream& operator>>(std::istream &is, static_modint &a) { i64 v; is >> v; a=static_modint(v%mod); return is; }
        friend std::ostream& operator<<(std::ostream &os, const static_modint &a) { os << a.val(); return os; }
        bool operator==(const static_modint& rhs) const { return x==rhs.x; }
        bool operator!=(const static_modint& rhs) const { return x!=rhs.x; }
    };
    using modint998244353=static_modint<998244353>;
    using modint1000000007=static_modint<1000000007>;
};

namespace sk {
    static int mod;
    struct dynamic_modint { 
        int x; 
        static void set_mod(int p) { assert(p>=1); mod=p; }
        int get_mod() const { return mod; }
        dynamic_modint(i64 x) : x(normal(x%mod)) {}
        dynamic_modint(): x(0) {}
        int normal(int x) { if (x>=mod) x-=mod; if (x<0) x+=mod; return x; }
        int val() const { return x; }
        dynamic_modint inv() const { assert(x!=0); return dynamic_modint(inverse(x, mod)); }
        dynamic_modint pow(int x) const { assert(x>=0); dynamic_modint a=*this, res=1;
            while (x) { if (x&1) res*=a; a*=a; x>>=1; } return res; }
        dynamic_modint operator-() const { return dynamic_modint(mod - x); }
        dynamic_modint& operator+=(const dynamic_modint &rhs) { x=normal(x+rhs.x); return *this; }
        dynamic_modint& operator-=(const dynamic_modint &rhs) { x=normal(x-rhs.x); return *this; }
        dynamic_modint& operator++() { return (*this)+=1; }
        dynamic_modint& operator--() { return (*this)-=1; }
        dynamic_modint& operator*=(const dynamic_modint &rhs) { x=i64(x)*rhs.x%mod; return *this; }
        dynamic_modint& operator/=(const dynamic_modint &rhs) { return *this *= rhs.inv(); }
        friend dynamic_modint operator+(const dynamic_modint &lhs, const dynamic_modint &rhs) { dynamic_modint res=lhs; res+=rhs; return res; }
        friend dynamic_modint operator-(const dynamic_modint &lhs, const dynamic_modint &rhs) { dynamic_modint res=lhs; res-=rhs; return res; }
        friend dynamic_modint operator*(const dynamic_modint &lhs, const dynamic_modint &rhs) { dynamic_modint res=lhs; res*=rhs; return res; }
        friend dynamic_modint operator/(const dynamic_modint &lhs, const dynamic_modint &rhs) { dynamic_modint res=lhs; res/=rhs; return res; }
        friend std::istream& operator>>(std::istream &is, dynamic_modint &a) { i64 v; is >> v; a = dynamic_modint(v); return is; }
        friend std::ostream& operator<<(std::ostream &os, const dynamic_modint &a) { os << a.val(); return os; }
        bool operator==(const dynamic_modint& rhs) const { return x==rhs.x; }
        bool operator!=(const dynamic_modint& rhs) const { return x!=rhs.x; }
    };
};



#define int long long 
using ll=sk::dynamic_modint;
constexpr int MAXN=1e6+1e3;
int n, m, a, p, q;
#define int long long 
int qpow(int a, int n) {
    int res=1; 
    while (n) {
        if (n&1) res=res*a%q;
        a=a*a%q; n>>=1;
    }
    return res;
}
#define inv(a) qpow(a,q-2)
int fac[MAXN], ifac[MAXN];

int phi(int p) {
    int res=p;
    for (int i=2; i*i<=p; ++i) {
        if (p%i==0) {
            res=res/i*(i-1);
            while (p%i==0) p/=i;
        }
    }
    if (p>1) res=res/p*(p-1);
    return res;
}

int get_ord(int a, int p) {
    int ans=p;
    for (int i=1; i*i<=p; ++i) {
        if (p%i) continue;
        if (ll(a).pow(i)==1)
            ans=min(ans,i);
        if (ll(a).pow(p/i)==1)
            ans=min(ans,p/i);
    }
    return ans;
}

int C(int n, int m) {
    if (m>n || m<0) return 0;
    return fac[n]*ifac[n-m]%q*ifac[m]%q;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>a>>p; ll::set_mod(p);
    q=get_ord(a,phi(p));
    fac[0]=ifac[0]=1;
    for (int i=1; i<=m; ++i)
        fac[i]=fac[i-1]*i%q,
        ifac[i]=ifac[i-1]*inv(i)%q;
    vector<ll> vec;
    for (int i=0,sum=0; i<n; ++i) {
        sum=(sum+C(m,i))%q;
        vec.push_back(ll(a).pow(sum));
    }
    reverse(vec.begin(),vec.end());
    for (auto i: vec) cout<<i<<" ";
}