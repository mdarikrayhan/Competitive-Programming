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

const ll N = 3e5 + 5e4;
ll mod = 1e9 + 7;
const ll sqr = 700;
const ll inf = 1e9 + 123;
const ld eps = 1e-12;
const ld P = acos( -1.0 );

typedef ve< ve< int > > matrix;

matrix operator*( matrix a , matrix b )
{
    matrix c;

    int n1 = sz( a );
    int m = sz( b );
    int n2 = sz( b[0] );

    c.resize( n1 , ve< int >( n2 , mod ) );

    for( int i = 0;i < n1;++ i )
    {
        for( int j = 0;j < n2;++ j )
        {
            for( int l = 0;l < m;++ l )
            {
                c[i][j] += ( mod + a[i][l] * b[l][j] ) % mod;
                c[i][j] %= mod;
            }
        }
    }

    return c;
}

matrix ed;


matrix bin_pow( matrix a , int b )
{
    if( b == 0 )
    {
        return ed;
    }
    if( b == 1 )
    {
        return a;
    }

    if( b % 2 == 0 )
    {
        matrix c = bin_pow( a , b / 2 );

        return c * c;
    }

    return a * bin_pow( a , b - 1 );
}

void solve()
{
    ed =
    {
        { 1 , 0 , 0 , 0 , 0 , 0 },
        { 0 , 1 , 0 , 0 , 0 , 0 },
        { 0 , 0 , 1 , 0 , 0 , 0 },
        { 0 , 0 , 0 , 1 , 0 , 0 },
        { 0 , 0 , 0 , 0 , 1 , 0 },
        { 0 , 0 , 0 , 0 , 0 , 1 },
    };

    matrix a
    {
        { 2 , 1 , 1 , 1 , 0 , 0 },
        { 1 , 2 , 1 , 1 , 0 , 0 },
        { 1 , 0 , 1 , 0 , 0 , 0 },
        { 0 , 1 , 0 , 1 , 0 , 0 },
        { 1 , 1 , 1 , 1 , 1 , 0 },
        { 0 , 0 , 0 , 0 , 1 , 1 }
    };

    int n , x , y , dx , dy , t;
    cin >> n >> x >> y >> dx >> dy >> t;

    mod = n;

    matrix start
    {
        { x , y , dx , dy , 0 , 1 }
    };

    matrix ans = start * bin_pow( a , t );

    ans[0][0] = ( ans[0][0] + mod ) % mod;
    ans[0][1] = ( ans[0][1] + mod ) % mod;

    if( ans[0][0] == 0 ) ans[0][0] = n;
    if( ans[0][1] == 0 ) ans[0][1] = n;

    cout << ans[0][0] << ' ' << ans[0][1] << '\n';
}


int32_t main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen("coloring.in", "r", stdin);
//        freopen("coloring.out", "w", stdout);
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

