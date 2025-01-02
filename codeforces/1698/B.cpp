#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define endl "\n"

typedef long long ll;
typedef pair<ll, ll> pp;
typedef vector<ll> vl;
typedef vector<int> vi;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

const ll mod = 1e9 + 7;
const int N = 1e6 + 5;
bool prime[N + 1];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void sieve() {
    int n = 1e6;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = 0;
}

void add_divs(ll x, map<ll, ll>& divs) {
    ll i = 2;
    while (i * i <= x) {
        while (x % i == 0) {
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if (x > 1) divs[x]++;
}

int num, f = 0, mid, n;

ll n1;
ll se = 0;

ll op(ll x, ll y) {
    return (x ^ y);
}

struct segment_tree {
    vector<ll> tree;

    void init(int num, const vector<ll>& a) {
        n1 = num;
        tree.assign(4 * n1, se);
        build(a);
    }

    void build(const vector<ll>& a, int v = 1, int tl = 0, int tr = n1 - 1) {
        if (tl == tr) {
            tree[v] = a[tr];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = op(tree[2 * v], tree[2 * v + 1]);
    }

    ll query(int l, int r, int v = 1, int tl = 0, int tr = n1 - 1) {
        if (l > r) {
            return se;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int md = (tl + tr) / 2;
        return op(query(l, min(md, r), 2 * v, tl, md), query(max(md + 1, l), r, 2 * v + 1, md + 1, tr));
    }

    void upd(int pos, int val, int v = 1, int tl = 0, int tr = n1 - 1) {
        if (tl > pos || pos > tr) {
            return;
        }
        if (tl == tr) {
            tree[v] = val;
            return;
        }
        int md = (tl + tr) / 2;
        if (pos <= md) {
            upd(pos, val, 2 * v, tl, md);
        } else {
            upd(pos, val, 2 * v + 1, md + 1, tr);
        }
        tree[v] = op(tree[2 * v], tree[2 * v + 1]);
    }
};

void solve() {
    int n,k;
    cin >> n>>k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt=0;
    for (int i = 1; i < n-1; i++) {
        if(a[i]>a[i-1]+a[i+1]){
            cnt++;
        }
    }
    if(k==1){
        cout << (n-1)/2<<endl;
        return;
    }
    cout << cnt << endl;
    return;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
