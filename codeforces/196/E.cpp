#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 
 
using namespace std;
using namespace __gnu_pbds;
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree< ll, null_type, less_equal < ll >, rb_tree_tag, tree_order_statistics_node_update > oset;
 
 
 
#define all(x) x.begin(),x.end()
#define sz(x) int64_t(x.size())
#define pii pair < int , int >
#define pll pair< ll , ll >
#define pld pair< ld , ld >
#define pb push_back
#define pf push_front
#define PB push_back
#define ve vector
#define S second
#define F first
#define int ll
#define itn int
 
mt19937_64 gen(chrono::system_clock().now().time_since_epoch().count());
 
const ll N = 2e5 + 4e5;
const ll mod = 1e9 + 7;
const ll sqr = 700;
const ll inf = 1e18 + 123;
const ld eps = 1e-12;
const ld P = acos( -1.0 );
 
ve< pll > g[N];
 
int d[N] , p[N];
 
pll ed[N];
 
int cost[N];
 
bool comp( int a , int b )
{
    int s1 = cost[a] + d[ed[a].F] + d[ed[a].S];
    int s2 = cost[b] + d[ed[b].F] + d[ed[b].S];
 
    return s1 < s2;
}
 
int pr[N] , sz[N];
 
 
int root( int v )
{
    if( v == pr[v] )
    {
        return v;
    }
 
    return pr[v] = root( pr[v] );
}
 
 
void Union( int a , int b )
{
    a = root( a );
    b = root( b );
 
    if( a == b )
    {
        return;
    }
 
    if( sz[a] < sz[b] )
    {
        swap( a , b );
    }
 
    pr[b] = a;
    sz[a] += sz[b];
}
 
 
 
void solve()
{
    int n , m;
    cin >> n >> m;
 
    for( int i = 0;i < n;++ i )
    {
        sz[i] = 1;
        pr[i] = i;
    }
 
    ve< int > need;
 
    for( int i = 0;i < m;++ i )
    {
        int v , u , w;
        cin >> v >> u >> w;
 
        -- v , -- u;
 
        g[v].pb( { u , w } );
        g[u].pb( { v , w } );
 
        ed[i] = { v , u };
        cost[i] = w;
 
        need.pb( i );
    }
 
    int k;
    cin >> k;
 
    fill( d , d + n , inf );
    fill( p , p + n , -1 );
 
    set< pll > st;
 
    for( int i = 0;i < k;++ i )
    {
        int x;
        cin >> x;
 
        -- x;
 
        d[x] = 0;
        p[x] = x;
 
        st.insert( { 0 , x } );
    }
 
    while( sz( st ) )
    {
        int v = ( *st.begin() ).S;
 
        st.erase( *st.begin() );
 
        for( auto to : g[v] )
        {
            if( d[to.F] > d[v] + to.S )
            {
                if( st.count( { d[to.F] , to.F } ) );
                {
                    st.erase( { d[to.F] , to.F } );
                }
 
                d[to.F] = d[v] + to.S;
                p[to.F] = p[v];
 
                st.insert( { d[to.F] , to.F } );
            }
        }
    }
 
//    return;
 
    sort( all( need ) , comp );
 
    int ans = 0;
 
    for( auto to : need )
    {
        int v , u;
 
        v = ed[to].F , u = ed[to].S;
 
 
        if( p[v] != p[u] && root( p[v] ) != root( p[u] ) )
        {
            Union( p[u] , p[v] );
 
            ans += d[v] + d[u] + cost[to];
        }
    }
 
    ans += d[0];
 
    cout << ans << '\n';
 
 
}
 
int32_t main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen("connect.in", "r", stdin);
//        freopen("connect.out", "w", stdout);
    #endif // LOCAL
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
//    cin >> t;
 
    while( t -- )
    {
        solve();
    }
}