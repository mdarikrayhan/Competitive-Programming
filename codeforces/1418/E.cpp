
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
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int> d(n);
    for(int i=0;i<n;++i){
        cin>>d[i];
    }
    sort(d.begin(),d.end());
  vector<int> pref(n+1);
  for(int i=1;i<=n;++i){
      pref[i]=(pref[i-1]+d[i-1])%mod;
  }
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        int pos=lower_bound(d.begin(),d.end(),b)-d.begin();
       
        int big=n-pos;
        pos++;
        if(big-a<0){
            cout<<0<<'\n';
            continue;
        }
    Modint big_prob=Modint(big-a);
  
    big_prob/=big;
   // cout<<big_prob<<" ";
    Modint e_big=big_prob*(pref[n]-pref[pos-1]);
   
    Modint small_prob=Modint(big-a+1);
    small_prob/=(big+1);
    Modint e_small=small_prob*pref[pos-1];
    Modint tot=e_big+e_small;
    cout<<tot<<'\n';
    
    }
 
    return 0;
}