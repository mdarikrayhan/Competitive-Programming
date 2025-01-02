#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int mxN = 1e6 + 5;

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

struct seg{
        int sz;
        vector<ll> dat;
        seg(int s){
                sz = s;
                int cur = 1;
                while((1 << cur) < sz * 2) cur++;
                dat.assign((1 << (cur + 1)), 0LL);
        }
        void update(int i, int s, int e, int x, ll v){
                if(s == e){
                        dat[i] += v;
                        return;
                }
                int m = (s + e) / 2;
                if(x <= m) update(i << 1, s, m, x, v);
                else update(i << 1 | 1, m + 1, e, x, v);
                dat[i] = dat[i << 1] + dat[i << 1 | 1];
        }
        void update(int x, ll v){
                update(1, 0, sz, x, v);
        }
        ll query(int i, int s, int e, int x, int y){
                if(e < x || y < s) return 0;
                if(x <= s && e <= y) return dat[i];
                int m = (s + e) / 2;
                return query(i << 1, s, m, x, y) + query(i << 1 | 1, m + 1, e, x, y);
        }
        ll query(int x, int y){
                if(x > y) return 0;
                return query(1, 0, sz, x, y);
        }
};

vector<pi> Q[mxN];
vi d[mxN];
int p[mxN];
int cnt[mxN * 20];
int pre[mxN];

void solve(){
        int n, q;
        cin >> n >> q;
        rep(i, n) Q[i].clear();
        vi a(n), pos(n + 1);
        rep(i, n){
                cin >> a[i];
                pos[a[i]] = i;
        }
        rep(i, q){
                int l, r;
                cin >> l >> r;
                l--, r--;
                Q[r].pb({l, i});
        }
        seg tree(n + 1);
        vector<ll> ans(q, 0LL);
        repn(i, 1, n + 1){
                for(int x : d[i]){
                        cnt[pre[x - 1] + i / x] = 0;
                }
        }
        rep(i, n){
                for(int x : d[a[i]]) if(pos[x] <= i){
                        ll tot = 1LL;
                        int v = a[i] / x;
                        for(int y : d[v]) if(y > 1){
                                int z = x * y;
                                if(pos[z] < i){
                                        tot += cnt[pre[x - 1] + y];
                                }
                        }
                        cnt[pre[x - 1] + v] = tot;
                        tree.update(pos[x], tot);
                }
                for(pi x : Q[i]){
                        ans[x.se] = tree.query(x.fi, i);
                }
        }
        rep(i, q) cout << ans[i] << ' ';
        cout << '\n';
}
 
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
        d[1] = {1};
        repn(i, 2, mxN) if(!p[i]){
                p[i] = i;
                for(int j = i + i; j < mxN; j += i) p[j] = i;
        }
        pre[0] = 0;
        repn(i, 1, mxN) pre[i] = pre[i - 1] + mxN / i;
        repn(i, 2, mxN){
                int v = i / p[i];
                for(int x : d[v]) d[i].pb(x);
                for(int x : d[v]) d[i].pb(x * p[i]);
                make_unique(d[i]);
                reverse(all(d[i]));
        }
        int t = 1;
        cin >> t;
        while(t--) solve();
        return 0;
}