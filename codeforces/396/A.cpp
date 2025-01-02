#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define int long long
#define el "\n"
using namespace std;
const ll mod = 1e9+7;
const ll oo = 1e18;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
int a[505], nt[100005];
ll gt[100005], igt[100005];
unordered_map<int, ll> mp;
vector<int> v, lmao;

void sang() {
    nt[0] = nt[1] = 1;
    for (int i=2; i<=sqrt(1e5); i++) {
        if (nt[i] == 0) {
            for (int j=i; j*i<=i; j++) nt[i*j] = 1;
        }
    }
    for (int i=2; i<=1e5; i++) {
        if (nt[i] == 0) v.pb(i);
    }
}

void pt(int x) {
    for (int i:v) {
        if (x%i == 0) {
            if (mp[i] == 0) lmao.pb(i);
            while(x%i == 0) {
                x /= i;
                mp[i]++;
            }
        }
    }
    if (x != 1) {
        if (mp[x] == 0) lmao.pb(x);
        mp[x]++;
    }
}

ll pw(ll x, int y) {
    ll res = 1;
    while(y>0) {
        if (y%2) res = res*x%mod;
        y /= 2;
        x = x*x%mod;
    }
    return res;
}

ll nCk(ll N, ll K) {
    if (N < K) return 0;
    return gt[N]*igt[K]%mod*igt[N-K]%mod;
}

ll ec(ll cd, ll pp) {
    return nCk(cd + pp - 1, pp-1);
}

void solve() {
    sang();
    cin>>n;
    gt[0] = 1;
    for (int i=1; i<=100000; i++) gt[i] = (gt[i-1]*i)%mod;
    igt[100000] = pw(gt[100000], mod-2);
    for (int i=1e5-1; i>=0; i--) igt[i] = (igt[i+1]*(i+1))%mod;
    sang();
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        pt(x);
    }
    ll kq = 1;
    for (int i=0; i<lmao.size(); i++) {
        //cout<<lmao[i]<<" "<<mp[lmao[i]]<<" ";
        int cnt = mp[lmao[i]];
        kq = kq*ec(cnt, n)%mod;
        //cout<<kq<<"\n";
    }
    cout<<kq;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--) solve();
}
