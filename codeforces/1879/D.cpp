#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
#define pb push_back
#define ff first
#define ss second
#define ins insert
const int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin>>n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        p[i] = p[i - 1] ^ a[i];
    }
    const int lg = 31;
    ll out = 0;
    for (int i = 0; i < lg; i++){
        vector<pil> cnt(2); cnt[0] = {1, 0};
        int v = (1 << i);
        for (int j = 1; j <= n; j++){
            bool bit = (p[j] >> i) & 1;
            auto &[x, y] = cnt[!bit];
            out += (1LL * v * ((1LL * j * x - y) % mod)) % mod;
            cnt[bit].ff++;
            cnt[bit].ss += j;
        }
        out %= mod;
    }
    cout<<(out + mod) % mod<<"\n";
}