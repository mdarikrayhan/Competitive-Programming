//Not all efforts result in success, but giving up is sure to result in failure.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <numeric>
#include <bitset>
#include <functional>
#include <iomanip>
using namespace std;
typedef long long  LL;
typedef unsigned long long uLL;
typedef pair<LL,LL> PII;
//typedef tuple<LL,LL,LL> tup;
#define make_pair() mk
#define int long long
const int N = 20;
const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<'\n';
#define pdebug(a,b) cout<<(#a)<<':'<<a<<' '<<(#b)<<':'<<b<<'\n'
#define tdebug(a,b,c) cout<<(#a)<<':'<<a<<' '<<(#b)<<':'<<b<<' '<<(#c)<<':'<<c<<'\n'
#define videbug(a) cout<<(#a)<<':';for(int i=0;i<a.size();i++)cout<<' '<<a[i];cout<<'\n';
//   Make bold hypotheses and verify carefully
// - You REALLY need some key observations...
// - Don't trust seemaxgly trival conclusions
// - Do something instead of nothing and stay organized
// - Don't get stuck on one approach
// - Formalization is the death of intuition
template <int T>
struct ModInt {
    const static int MD = T;
    int x;
    ModInt(LL x = 0)
        : x(x % MD) {}
    int get() { return x; }
    ModInt operator+(const ModInt& that) const {
        int x0 = x + that.x;
        return ModInt(x0 < MD ? x0 : x0 - MD);
    }
    ModInt operator-(const ModInt& that) const {
        int x0 = x - that.x;
        return ModInt(x0 < MD ? x0 + MD : x0);
    }
    ModInt operator*(const ModInt& that) const {
        return ModInt((long long)x * that.x % MD);
    }
    ModInt operator/(const ModInt& that) const {
        return *this * that.inverse();
    }
    void operator+=(const ModInt& that) {
        x += that.x;
        if (x >= MD)
            x -= MD;
    }
    void operator-=(const ModInt& that) {
        x -= that.x;
        if (x < 0)
            x += MD;
    }
    void operator*=(const ModInt& that) { x = (long long)x * that.x % MD; }
    void operator/=(const ModInt& that) { *this = *this / that; }
    ModInt inverse() const {
        int a = x, b = MD, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0)
            u += MD;
        return u;
    }
    friend ostream& operator<<(ostream& os, ModInt x) {
        os << x.get();
        return os;
    }
};
const int mod=998244353;
typedef ModInt<mod> mint;
const LL mod1=2147483648;
LL gcd(LL a, LL b)
{
   return b ? gcd(b, a % b) : a;
}
void solve()
{
   int a,b,c,d;cin>>a>>b>>c>>d;
   if(b>=a){
     cout<<b<<'\n';
   }else{
      if(c<=d){
         cout<<-1<<"\n";
      }else{
         cout<<(a-b+c-d-1)/(c-d)*c+b<<'\n';
      }
   }
}
signed main()
{
  ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
  int t;t=1;
  cin>>t;
  while(t--) solve();
}