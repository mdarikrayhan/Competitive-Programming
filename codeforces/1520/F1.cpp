#include <bits/stdc++.h>

#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define F first
#define S second
#define fast                         \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(0);                      \
    cout.tie(0);
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const int ddg = 2e5 + 10;
vector<ll> graph[ddg];
ll y[ddg], x[ddg], vis[ddg], dsu[ddg], sz[ddg];
ll a, b, c, n, m, k, d, ans = 0, cnt = 0;
ll mod = 1e9 + 7;
string s, s1;
int nx[] = {0, 0, 1, -1}, ny[] = {-1, 1, 0, 0};

bool inside(ll x, ll y) { return (x >= 0 && y >= 0 && x < 2 && y < n); }

ll add(ll x, ll y) {
    x %= mod;
    y %= mod;
    return (x + y) % mod;
}

ll power(ll a, ll n) {
    ll sum = 1;
    for (int i = 0; i < n; i++)sum = ((sum % mod) * (a % mod)) % mod;
    return sum;
}

bool is_rsorted(ll arr[]) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])
            return false;
    }
    return true;
}

void dfs(ll v) {
    vis[v] = 1;
    // ans++;
    for (auto x: graph[v]) {
        if (!vis[x])dfs(x);
    }
}

ll get(ll v) {
    if (dsu[v] == v)return v;
    else return dsu[v] = get(dsu[v]);
}

void unite(ll a, ll b) {
    a = get(a);
    b = get(b);
    if (a == b)return;
    if (sz[a] < sz[b])swap(a, b);
    dsu[a] = b;
    sz[b] += sz[a];
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n - i) - log(i + 1);
    }
    return (ll) round(exp(res));
}

int main() {
    fast
    ll t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> b >> k;
        ll l = 1, r = n, mid;
        while (r >= l) {
            mid = (l + r) / 2;
            if(l==r)break;
            cout << "? " << l << ' ' << mid << endl;
            cin >> a;
            ll zeros = mid - l + 1 - a;
            if (zeros < k)l = mid + 1, k -= zeros;
            else r = mid;
           // cout<<k<<endl;
        }

         cout << "! " << l << endl;
    }

    return 0;
}