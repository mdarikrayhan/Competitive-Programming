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

mt19937 gen (chrono::system_clock().now().time_since_epoch().count());

const ll N = 1e5 + 123;
const ll mod = 1e9;
const ll sqr = 700;
const ll inf = 1e18 + 123;
const ld eps = 1e-12;
const ld P = acos( -1.0 );

struct CHT
{
    struct line
    {
        int k , b;
        ld min_x;
    };

    ve< line > v;

    int get( int x , line a )
    {
        return a.k * x + a.b;
    }

    ld per( line a , line b )
    {
        int k = a.k - b.k;

        if( k == 0 )
        {
            return (ld)( -inf );
        }

        return ld( b.b - a.b ) / ld( k );
    }


    void add( line a )
    {
        while( sz( v ) )
        {
            if( per( v.back() , a ) < ( v.back() ).min_x )
            {
                v.pop_back();
            }
            else
            {
                break;
            }
        }

        if( sz( v ) == 0 )
        {
            a.min_x = -inf;
        }
        else
        {
            a.min_x = per(  a , v.back() );
        }

        v.pb( a );
    }

    int get_y( int x )
    {
        int l = 0, r = sz( v ) - 1;

        int ans = inf;

        while( l <= r )
        {
            int mid = ( l + r ) / 2;

            if( v[mid].min_x <= ld( x ) )
            {
                ans = min( ans , get( x , v[mid] ) );
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};

CHT t[4 * N];

int st = ( 1ll << 17 );

int pr[N];

void upd( int v , int k , int b )
{
    while( v )
    {
        t[v].add( { k , b } );
        v /= 2;
    }
}

int get( int v , int vl , int vr , int l , int r , int x )
{
//    cerr << v << ' ' << vl << ' ' << vr << ' ' << l << ' ' << r << ' ' << x << '\n';
    if( vl > r || vr < l )
    {
//        cerr << "!\n";
        return inf;
    }

    if( vl >= l && vr <= r )
    {
//        cerr << "?\n";
        return t[v].get_y( x );
    }

    int mid = ( vl + vr ) / 2;

    return min( get( v * 2 , vl , mid , l , r , x ) , get( v * 2 + 1 , mid + 1 , vr , l , r , x ) );
}

void solve()
{
    int n;
    cin >> n;

    int a[n + 1];

    ve< pair< pll , int > > p;

    for( itn i = 1;i <= n;++ i )
    {
        cin >> a[i];

        pr[i] = pr[i - 1] + a[i];

        p.pb( { { a[i] , a[i] * i - pr[i] } , i } );
    }

    sort( all ( p ) );
    reverse( all( p ) );

    for( auto to : p )
    {
//        cout << to.F.F << ' '<< to.F.S << ' ' << to.S << '\n';
        upd( to.S + st , to.F.F , to.F.S );
    }

//    return;

    int m;
    cin >> m;

    while( m -- )
    {
        int x , y;
        cin >> x >> y;

        cout << pr[y] + get( 1 , 0 , st - 1 , max( 1ll , y - x + 1 ) , y , ( x - y ) ) << '\n';
    }


}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen("cover.in", "r", stdin);
//        freopen("cover.out", "w", stdout);
    #endif

    int t = 1;
//    cin >> t;

    while( t -- )
    {
        solve();
    }
}
