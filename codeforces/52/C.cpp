#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define mh ios::sync_with_stdio(false);cin.tie(0)
#define rvs(v) reverse(v.begin(),v.end())
#define F first
#define S second
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define nl '\n'
#define rep(i,n) for(int i=0; i<n; i++)
#define rev(i,n) for(int i=n-1; i>=0; i--)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<nl
#define cinv(v) for(auto &it:v)cin>>it
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
using namespace std;

const int N = 3e5 + 9;
const ll inf = -1e18-1e8;

ll a[N];

struct SegmentTree
{
    vector<ll> tree, lazy;

    #define lc (nd << 1)
    #define rc ((nd << 1) | 1)

    SegmentTree(int n)
    {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, inf);
    }

    inline void uthao(int nd) {
        tree[nd] = min(tree[lc],tree[rc]);
    }

    inline ll milao(ll x, ll y) {
        return min(x,y);
    }

    void push(int nd, int b, int e)
    {
        if (lazy[nd] == inf) return;
        tree[nd] += lazy[nd];
        if (b != e)
        {
            if(lazy[lc]==inf) lazy[lc] = lazy[nd];
            else lazy[lc] += lazy[nd];
            if(lazy[rc]==inf) lazy[rc] = lazy[nd];
            else lazy[rc] += lazy[nd];
        }
        lazy[nd] = inf;
    }

    void build(int nd, int b, int e)
    {
        if (b == e)
        {
            tree[nd] = a[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        uthao(nd);
    }

    ll query(int nd, int b, int e, int l, int r)
    {
        push(nd, b, e);
        if (r < b || l > e) return -inf;
        if (l <= b && r >= e)
        {
            return tree[nd];
        }
        int mid = (b + e) >> 1;
        return milao(query(lc, b, mid, l, r), query(rc, mid + 1, e, l, r));
    }

    void update(int nd, int b, int e, int l, int r, ll val)
    {
        push(nd, b, e);
        if (r < b || l > e) return;
        if (l <= b && r >= e)
        {
            lazy[nd] = val;
            push(nd, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        update(lc, b, mid, l, r, val);
        update(rc, mid + 1, e, l, r, val);
        uthao(nd);
    }
};

void solve()
{
    int n;
    cin >> n;
    rep(i,n) cin>>a[i];
    SegmentTree seg(n);
    seg.build(1,0,n-1);

    int m;
    cin>>m;
    rep(ii, m)
    {
        ll t, l, r, v = inf;
        cin >> l >> r;
        if (cin.peek()!='\n') cin>>v;
        if (v == inf)
        {
            ll ans;
            if(l<=r) ans =  seg.query(1, 0, n-1, l, r);
            else ans = min(seg.query(1, 0, n-1, l, n-1),  seg.query(1, 0, n-1, 0, r));
            cout << ans << nl;
        }
        else
        {
            if(l<=r) seg.update(1, 0, n-1, l, r, v);
            else {
                seg.update(1, 0, n-1, l, n-1, v);
                seg.update(1, 0, n-1, 0, r, v);
            }

        }
    }


}

int main()
{
    mh;
    solve();
    return 0;
}
