#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


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
//#define int ll
#define itn int

mt19937_64 gen(chrono::system_clock().now().time_since_epoch().count());

const ll N = 16e5 + 123;
const ll mod = 32768;
const ll INF = 1e9 + 123;
const ld eps = 1e-12;
const ld P = acos( -1.0 );

int t[N][2] , lz[N][2];

int tin[N] , tout[N] , timer = 0;

ve< pll > g[N];

int st = 1;

void push( int v , int T )
{
    if( lz[v][T] == 0 )
    {
        return;
    }

    t[v][T] += lz[v][T];

    if( v * 2 + 1 < N )
    {
        lz[v * 2][T] += lz[v][T];
        lz[v * 2 + 1][T] += lz[v][T];
    }

    lz[v][T] = 0;
}

void upd( int v , int vl , int vr , int l , int r , int d , int T )
{
    push( v , T );

    if( vl > r || vr < l )
    {
        return;
    }

    if( vl >= l && vr <= r )
    {
        lz[v][T] += d;

        push( v , T );

        return;
    }

    if( vl == vr )
    {
        return;
    }

    int mid = ( vl + vr ) / 2;

    upd( v * 2 , vl , mid , l , r , d , T );
    upd( v * 2 + 1 , mid + 1 , vr , l , r , d , T );

    t[v][T] = min( t[v * 2][T] , t[v * 2 + 1][T] );
}

int get( int v , int vl , int vr , int l , int r , int T )
{
    push( v , T );

    if( vl > r || vr < l )
    {
        return INF;
    }

    if( vl >= l && vr <= r )
    {
        return t[v][T];
    }

    int mid = ( vl + vr ) / 2;

    return min( get( v * 2 , vl , mid , l , r , T ) , get( v * 2 + 1 , mid + 1 , vr , l , r , T ) );
}

void dfs( int v , int d )
{
    tin[v] = ++ timer;

    upd( 1 , 0 , st - 1 , timer , timer , -INF + d , 1 );

    for( auto to : g[v] )
    {
        if( tin[to.F] == 0 )
        {
            dfs( to.F , d + to.S );
            continue;
        }

        upd( 1 , 0 , st - 1 , tin[v] , tin[v] , -INF + d + to.S , 0 );
    }

    tout[v] = ++ timer;

}

pll ed[2 * N];
int cost[2 * N];

void solve()
{
    int n , q;
    cin >> n >> q;

    

    for( int i = 0;i < 2 * n - 2;++ i )
    {
        int v , u , d;
        cin >> v >> u >> d;

        -- v , -- u;

        g[v].pb( { u , d } );

        ed[i] = { v , u };
        cost[i] = d;
    }

    while( st <= n * 2 )
    {
        st *= 2;
    }

    for( int i = 0;i < N;++ i )
    {
        t[i][0] = t[i][1] = INF;
    }

    dfs( 0 , 0 );

    while( q -- )
    {
        int T , u , v;
        cin >> T >> v >> u;

        if( T == 1 )
        {
            int i = v - 1;

            v = ed[i].F;

            if( ed[i].S == 0 )
            {
                upd( 1 , 0 , st - 1 , tin[v] , tin[v] , u - cost[i] , 0 );
                cost[i] = u;
            }
            else
            {
                v = ed[i].S;

//                cout << tin[v] << ' ' << tout[v] << ' '  << u - cost[i] << '\n';
//
//                cout << get( 1 , 0 , st - 1 , tin[v] , tin[v] , 1 );

                upd( 1 , 0 , st - 1 , tin[v] , tout[v] , u - cost[i] , 0 );
                upd( 1 , 0 , st - 1 , tin[v] , tout[v] , u - cost[i] , 1 );

                cost[i] = u;
            }
        }
        else
        {
            -- v , -- u;

//            cout << tin[u] << ' ' << tin[v] << ' ' << tout[v] << '\n';

            if( tin[u] >= tin[v] && tin[u] <= tout[v] )
            {
//                cout << "lca \n";

                int dv , du;

                dv = get( 1 , 0 , st - 1 , tin[v] , tin[v] , 1 );
                du = get( 1 , 0 , st - 1 , tin[u] , tin[u] , 1 );

//                cout << dv << ' ' << du << '\n';

                cout << du - dv << '\n';
            }
            else
            {
//                cout << "bu 0 \n";
                int dv0 , du;

                dv0 = get( 1 , 0 , st - 1 , tin[v] , tout[v] , 0 ) - get( 1 , 0 , st - 1 , tin[v] , tin[v] , 1 );
                du = get( 1 , 0 , st - 1 , tin[u] , tin[u] , 1 );

//                cout << dv0 << ' ' << du << '\n';

                cout << dv0 + du << '\n';
            }
        }
    }


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

