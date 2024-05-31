//#pragma GCC target("avx,avx2")
//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define int long long
#define mem(x,y)memset(x,y,sizeof(x))
#define rep(i,l,r)for(int i = l;i <= r;i ++)
#define dep(i,r,l)for(int i = r;i >= l;i --)
#define tov(i)for(int i = head[x];i;i = e[i].nxt)
#define pb push_back
#define pi pair <int,int> 

using namespace std;

int read(){
    int s = 0,w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

namespace Tem{
    const int mod = 0;//Notice Here!!!!!!!!!!
    int fac[1000010],ifac[1000010];

    inline int gcd(int a, int b){
        int az = __builtin_ctz(a);
        int bz = __builtin_ctz(b);
        int z = az > bz ? bz : az;
        int diff;
        b >>= bz;
        while(a){
            a >>= az;
            diff = b - a;
            az = __builtin_ctz(diff);
            if(a < b)b = a;
            a = diff < 0 ? -diff : diff;
        }
        return b << z;
    }

    inline int poww(int x,int y,int MOD = mod){
        int s = 1;
        for(;y;x = x * x % MOD,y >>= 1)if(y & 1)s = s * x % MOD;
        return s;
    }

    void initfac(int n,int MOD = mod){
        fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
        rep(i,2,n)fac[i] = fac[i - 1] * i % MOD;
        ifac[n] = poww(fac[n],MOD - 2,MOD);
        dep(i,n - 1,2)ifac[i] = ifac[i + 1] * (i + 1)% MOD;
    }

    inline int inv(int x,int MOD = mod){return poww(x,MOD - 2)% MOD;}

    inline int C(int x,int y,int MOD = mod){return fac[x] * ifac[y] % MOD * ifac[x - y] % MOD;}

    void Add(int &x,int y){x = x + y >= mod ? x + y - mod : x + y;}
    void Dec(int &x,int y){x = x - y < 0 ? x - y + mod : x - y;}
    void Mul(int &x,int y){x = x * y % mod;}
}using namespace Tem;

struct node{
    int pos;
    int w;
    int id;

    friend bool operator < (node x,node y){if(x.pos != y.pos)return x.pos < y.pos;return x.w < y.w;}
}e[1000010];

struct Edge{
    int x;
    int y;
    int w;

    friend bool operator < (Edge x,Edge y){return x.w < y.w;}
}a[1000010];

int t;
int n;
int cnt;
int cnte;
int pre[1000010];

int find(int x){if(pre[x] == x)return x;return pre[x] = find(pre[x]);}

set <pair <int,int> > q;//分别是值和编号

void add(int x,int w){
    if(q.size() == 0)return ;
  //  cout<<"x = "<<x<<",w = "<<w<<endl;
    auto it = q.lower_bound({w,-1});
    if(it != q.end()){
       // cout<<"houji : "<<(it -> first)<<endl;
        cnte ++;
        a[cnte] = {x,it -> second,abs((it -> first) - w)};
    }
    if(it == q.begin())return ;
    it --;
  //  cout<<"qianqu : "<<(it -> first)<<endl;
    cnte ++;
    a[cnte] = {x,it -> second,abs((it -> first) - w)};
}

void solve(){
    cnte = 0;
    n = read();
    cnt = 0;
    rep(i,1,n){
        int l,r,w;
        l = read(),r = read(),w = read();
        cnt ++;
        e[cnt] = {l,w,i};
        cnt ++;
        e[cnt] = {r + 1,-w,i};
    }
    q.clear();
    sort(e + 1,e + cnt + 1);
    rep(i,1,cnt){
        if(e[i].w < 0)q.erase({-e[i].w,e[i].id});
        else {
            add(e[i].id,e[i].w);
            q.insert({e[i].w,e[i].id});
        }
    }
    rep(i,1,n)pre[i] = i;
    int ans = 0;
    int cntt = 0;
    sort(a + 1,a + cnte + 1);
    rep(i,1,cnte){
        int x = a[i].x,y = a[i].y,w = a[i].w;
        if(find(x) == find(y))continue;
       // cout<<"x = "<<x<<",y = "<<y<<",w = "<<w<<endl;
        pre[find(x)] = find(y);
        ans += a[i].w;
        cntt ++;
        if(cntt == n - 1)break;
    }
    if(cntt != n - 1)ans = -1;
    printf("%lld\n",ans);
}

signed main(){
    // q.insert({2,3});q.insert({3,3});
    // auto it = q.lower_bound({4,2});
    // if(it == q.end())puts("dick");
    cin>>t;
    while(t --)solve();
}