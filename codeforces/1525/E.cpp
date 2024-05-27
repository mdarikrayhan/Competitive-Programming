
#include <bits/stdc++.h>
#define int long long 
using namespace std;



const int mod=998244353;
class Modint{
    int val;
    public:
   
    Modint(int val=0){
        this->val=val;
    }
    int get() const{
        return val;
    }
    int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
 Modint power(int p) const{
    Modint res(1);
    Modint a=*this;
    while(p){
        if(p&1)
        res*=a;
        a*=a;
        p>>=1;
        
    }
    return res;
    
}
void operator+=(const Modint &rhs){
    val=norm(val+rhs.val);

}
void operator-=(const Modint &rhs){
    val=norm(val-rhs.val);
}
void operator*=(const Modint &rhs){
    val=val*rhs.val%mod;
}
void operator/=(const Modint &rhs){
    Modint p=rhs.power(mod-2);

    *this*=p;
   
}

 friend Modint operator*(const Modint &lhs, const Modint &rhs) {
        Modint res = lhs;
        res *= rhs;
        return res;
    }
    friend Modint operator+(const Modint &lhs, const Modint &rhs) {
     
        Modint res = lhs;
        res += rhs;
        return res;
    }
    friend Modint operator-(const Modint &lhs, const Modint &rhs) {
        Modint res = lhs;
        res -= rhs;
        return res;
    }
    friend Modint operator/(const Modint &lhs, const Modint &rhs) {
           
        Modint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Modint &a) {
        int v;
        is >> v;
        a = Modint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Modint &a) {
        return os << a.get();
    }
     
};
const int N=21;
vector<Modint> fact(N+1);
void facti(){
    fact[0]=1;
    for(int i=1;i<=N;++i){
        fact[i]=i*fact[i-1];
    }
}
signed main()
{ facti();
   int n,m;
   cin>>n>>m;
   vector<vector<int>> d(n+1,vector<int> (m+1));
   for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           cin>>d[i][j];
       }
   }
   Modint e=0;
   Modint inv=1/fact[n];
   //inv/=fact[n];
   for(int j=0;j<m;++j){
       vector<int> cnt(n+2);
       for(int i=0;i<n;++i){
           cnt[n+2-d[i][j]]++;
       }
       Modint res=1;
       for(int i=1;i<=n;++i){
           if(cnt[i]>=0)res*=cnt[i];
           cnt[i+1]+=cnt[i]-1;
       }
       Modint p=(1-res*inv);
       e+=p;
       
   }
   cout<<e;

    return 0;
}
