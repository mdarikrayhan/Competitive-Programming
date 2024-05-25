#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int N = 2e5 + 1;
int a[N], add[N], spf[N], ans[N], g[N * 4];
vector<int> adj[N];
vector<int> vec;

int gcd(int a, int b) {return b? gcd(b, a % b): a;}

int lx,rx;
#define c1 i*2+1
#define c2 i*2+2
void update(int i, int v) {
    i += lx;
    g[i] = v;
    while(i) {
        i = (i - 1) / 2;
        g[i] = gcd(g[c1], g[c2]);
    }
}

int get_gcd(int l, int r, int i = 0, int ll = lx, int rr = rx) {
    if(!i) {
        l += lx;
        r += lx;
    }
    if(ll > r || rr < l)
        return 0;
    if(ll >= l && rr <= r)
        return g[i];
    int m = (ll + rr) / 2;
    int g1 = get_gcd(l, r, c1, ll, m);
    int g2 = get_gcd(l, r, c2, m + 1, rr);
    return gcd(g1, g2);
}

int findFirstNotDivisible(int v, int i = 0, int ll = lx, int rr = rx) {
    if(ll == rr)
        return i - lx;
    int m = (ll + rr) / 2;
    if(g[c2] % v == 0)
        return findFirstNotDivisible(v, c1, ll, m);
    else
        return findFirstNotDivisible(v, c2, m + 1, rr);
}

void solve() {
    vector<int> changed;
    int best = 1;
    int cur = vec.back();
    ans[cur] = 1;
    int x = a[cur];
    update(vec.size() - 1, x);
    while(x > 1) {
        int num = 1, p = spf[x];
        while(x % p == 0) {
            x /= p;
            num *= p;
            if(g[0] % num == 0)
                ans[cur] *= p;
            else {
                int ind = findFirstNotDivisible(num);
                if(get_gcd(0, ind - 1) % num == 0) {
                    if(!add[ind]) {
                        add[ind] = 1;
                        changed.push_back(ind);
                    }
                    add[ind] *= p;
                    best = max(best, add[ind]);
                }
            }
        }
    }
    ans[cur] *= best;
    if(vec.size() >= 2)
        ans[cur] = max(ans[cur], get_gcd(0, vec.size() - 2));
    for(auto it: changed)
        add[it] = 0;
}

void dfs(int x, int p) {
    vec.push_back(x);
    solve();
    for(auto u: adj[x]) {
        if(u != p)
            dfs(u, x);
    }
    vec.pop_back();
    update(vec.size(), 0);
}

void seive() {
    for(int i = 2; i < N; i++) {
        if(!spf[i]) {
            for(int j = i; j < N; j += i) {
                if(!spf[j])
                    spf[j] = i;
            }
        }
    }
}

main()
{
    fast;
    seive();
    int n; cin >> n;
    lx = 1; while(lx <= n) lx *= 2;
    lx--; rx = lx + lx;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
    
