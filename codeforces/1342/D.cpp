#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define vec vector
#define pb push_back
#define PDD pair<double,double>
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define INF 0x3f3f3f3f
#define i128 __int128
#define ld long double
#define pi acos(-1)
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

bool isprime(ll x) {
    if (x == 1)return false;
    for (ll i = 2; i <= x / i; i++) {
        if (x % i == 0)return false;
    }
    return true;
}

int popcnt(ll x) {
    int cnt = 0;
    while (x) {
        if (x & 1)cnt++;
        x >>= 1;
    }
    return cnt;
}

ll qmi(ll a, ll b, ll p) {
    a %= p;
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll lowbit(ll x) { return x & -x; }

const int N = 1e6 + 10;
ll fact[N], infact[N];
//ll C(ll n,ll m) {
//    if (n < m || m < 0)return 0;
//    return fact[n] * qmi(fact[m] * fact[n - m] % mod, mod - 2, mod) % mod;
//}
//ll C(ll n,ll m){
//    vec<ll>a,b;
//    for(int i=n-m+1;i<=n;i++)a.pb(i);
//    for(int i=2;i<=m;i++)b.pb(i);
//    ll res=1;
//    for(auto &x:a){
//        for(auto &y:b){
//            int g=gcd(x,y);
//            if(g>1)x/=g,y/=g;
//        }
//    }
//    for(auto x:a)res*=x;
//    return res;
//}
ll C(ll n, ll m) {
    if (n < m || m < 0)return 0;
    return fact[n] % mod * infact[m] % mod * infact[n - m] % mod;
}

//void scan(__int128 &x)
//{
//    x=0;int f=1;char ch=getchar();
//    while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
//    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
//    x*=f;
//}
//inline void print(__int128 x) {
//    if (x < 0) {
//        putchar('-');
//        x = -x;
//    }
//    if (x > 9) print(x / 10);
//    putchar(x%10+'0');
//}
//--------------------------------------
ll a[N],b[N],s[N];
void solve() {
    ll n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],s[a[i]]++;
    for(int i=k;i;i--)s[i]+=s[i+1];
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++)cin>>b[i];
    ll ans=0;
    for(int i=k;i;i--){
        ans=max(ans,(s[i]+b[i]-1)/b[i]);
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        int nw=i;
        int sz=0;
        while(nw<=n)nw+=ans,sz++;
        cout<<sz<<" ";
        nw=i;
        while(nw<=n)cout<<a[nw]<<" ",nw+=ans;
        cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
//    cin>>T;
    while (T--)solve();
    return 0;
}