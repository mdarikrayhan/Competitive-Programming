#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int mod[2] = {1000000007, 998244353};
const int N = 1e5 + 1;
const int T = 100;
const string NAME = "tworoads";
const int lim = 2147483647;
//const unsigned int lim = 4294967295;
//const long long lim = 9223372036854775807;
//const unsigned long long lim = 18446744073709551615;
const int mset = 0x3f;
const double pi = acos(-1);
int n;
ll p[N];
int lg[N];
ll st[20][N];

void init(){
    sort(p + 1, p + n + 1);
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for(int i = 1; i <= n; ++i)
        st[0][i] = {p[i].se, p[i].se};
    for(int l = 1; l <= lg[n]; ++l)
        for(int i = 1; i <= n - (1 << l) + 1; ++i)
            st[l][i] = {max(st[l - 1][i].fi, st[l - 1][i + (1 << (l - 1))].fi), min(st[l - 1][i].se, st[l - 1][i + (1 << (l - 1))].se)};
}

ll RMQ(int l, int r){
    if(l > r)
        return {-1e12, 1e12};
    int k = lg[r - l + 1];
    return {max(st[k][l].fi, st[k][r - (1 << k) + 1].fi), min(st[k][l].se, st[k][r - (1 << k) + 1].se)};
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i].fi >> p[i].se;
        long long a = p[i].fi - p[i].se;
        long long b = p[i].fi + p[i].se;
        p[i] = {a, b};
    }
}

void solve(){
    init();
    long double ans = 2e9, l = 0, r = 2e9;
    for(int ti = 1; ti <= T; ++ti){
        long double x = (l + r) / 2.0;
        bool isSmaller = false;
        for(int i = 1; i <= n; ++i){
            int j = i;
            int lo = i, hi = n;
            while(lo <= hi){
                int m = (lo + hi) / 2;
                long double lhs = p[i].fi + 2.0 * x;
                long double rhs = p[m].fi;
                if(lhs >= rhs){
                    j = m;
                    lo = m + 1;
                }
                else hi = m - 1;
            }
            ll posy = RMQ(1, i - 1);
            ll tmp = RMQ(j + 1, n);
            posy = {max(posy.fi, tmp.fi), min(posy.se, tmp.se)};
            long double val = (posy.fi - posy.se) / 2.0;
            if(val < x)
                isSmaller = true;
            ans = min(ans, max(val, x));
        }
        if(isSmaller)
            r = x;
        else l = x;
    }
    cout << setprecision(15) << fixed << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen((NAME + ".inp").c_str(), "r")){
        freopen((NAME + ".inp").c_str(), "r", stdin);
        freopen((NAME + ".out").c_str(), "w", stdout);
    }

    inp();
    solve();
}