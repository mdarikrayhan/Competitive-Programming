#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
#define int long long

const int MOD = 998244353;
const int MAX = 3e5+5;

const int INF = 0x3f3f3f3f3f3f3f3f;

struct mint {
    int x;
    mint(int _x = 0) : x(_x) { }
    mint operator +(const mint &o) const { return x + o.x >= MOD ? x + o.x - MOD : x + o.x; }
    mint operator *(const mint &o) const { return mint((int)x * o.x % MOD); }
    mint operator -(const mint &o) const { return *this + (MOD - o.x); }
    mint inv() { return pwr(MOD - 2); }
    mint pwr(int e) {
        mint ans = 1;
        for (mint b=x; e; e >>= 1, b = b * b)
            if (e & 1) ans = ans * b;
        return ans;
    }
};

mint fac[MAX], ifac[MAX];
void build_fac() {
    fac[0] = 1;
    for (int i=1;i<MAX;i++)
        fac[i] = fac[i-1] * i;
    ifac[MAX-1] = fac[MAX-1].inv();
    for (int i=MAX-2;i>=0;i--)
        ifac[i] = ifac[i+1] * (i+1);
}
mint c(int n, int k) {
    if (k > n) return 0;
    return fac[n] * ifac[k] * ifac[n-k];
}

int cnt1[MAX], cnt2[MAX];

void solve(){
    int n; cin>>n;

    vector<pair<int,int>> vp;
    for(int i=0; i<n+1; i++) cnt1[i] = cnt2[i] = 0;

    map<pair<int,int>, int> cnt12;

    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        vp.pb({a, b});
        cnt1[a]++;
        cnt2[b]++;
        cnt12[{a, b}]++;
    }

    sort(all(vp));
    mint ans = fac[n];

    mint c1 = 1;
    mint c2 = 1;
    for(int i=1; i<=n; i++){
        if(cnt1[i]) c1 = c1*fac[cnt1[i]];
        if(cnt2[i]) c2 = c2*fac[cnt2[i]];
    }

    // posso so reordenar os pares iguais
    mint c12 = 1;
    for(auto [val, qtd] : cnt12) c12 = c12*fac[qtd];

    // mas se eu não consigo reordenar?
    for(int i=0; i<n-1; i++){
        if(vp[i+1].second < vp[i].second) c12 = 0;
    }

    ans = (ans - c1 - c2 + c12);
    cout<<ans.x<<endl;
}

int32_t main(){
    build_fac();
    sws;
    int t = 1;
    while(t--) solve();
    return 0;
}

