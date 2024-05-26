#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;
const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll A, cf, cm, m;
pii a[maxn];
ll ps[maxn];

ll check(ll x){
    auto pos = lower_bound(a + 1, a + n + 1, pii(x, -1));
    int sz = pos - a - 1;
    return sz * x - ps[sz];
}

ll last_l;

ll solve(int suff, ll need){
    if(need > m){
        return -1;
    }
    n -= suff;
    ll l = a[1].first, r = A+1;
    while(r - l > 1){
        ll mid = (l + r)/2;
        if(check(mid) <= m - need){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    n += suff;
    last_l = l;
    return suff * cf + cm * l;
}

int Ans[maxn];

int32_t main(){
	cin >> n >> A >> cf >> cm >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; i ++){
        ps[i] = ps[i - 1] + a[i].first;
    }
    pii ans = {-1, 0};
    ll need = 0;
    for(int i = 0 ; i <= n ; i ++){
        ans = max(ans, {solve(i, need), i});
        need += A - a[n-i].first;
    }
    cout << ans.first << endl;
    need = 0;
    for(int i = 0 ; i < ans.second ; i ++){
        need += A - a[n - i].first;
    }
    solve(ans.second, need);
    for(int i = 0 ; i < ans.second ; i ++){
        a[n-i].first = A;
    }
    for(int i = 1 ; i <= n ; i ++){
        a[i].first = max(a[i].first, last_l);
    }
    for(int i = 1 ; i <= n ; i ++){
        Ans[a[i].second] = a[i].first;
    }
    for(int i = 1 ; i <= n ; i ++){
        cout << Ans[i] << ' ';
    }
	return(0);
}
