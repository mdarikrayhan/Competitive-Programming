#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


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
#define int ll
#define itn int

mt19937_64 gen(chrono::system_clock().now().time_since_epoch().count());

const ll N = 2e6 + 5e5;
const ll mod = 1e9 + 7;
const ll sqr = 700;
const ll inf = 3e9 + 123;
const ld eps = 1e-12;
const ld P = acos( -1.0 );

ld t[N] , k[N] , b[N];
int st = 1;



void push( int v , int sz )
{
    t[v] = t[v] * k[v] + sz * b[v];

    if( sz > 0 )
    {
        k[v * 2] *= k[v];
        k[v * 2 + 1] *= k[v];

        b[v * 2] = b[v * 2] * k[v] + b[v];
        b[v * 2 + 1] = b[v * 2 + 1] * k[v] + b[v];
    }

    k[v] = 1.0;
    b[v] = 0.0;

}

void upd( int v , int vl , int vr , int l , int r , ld K , ld B )
{
//    cout << v << ' ' << vl << ' ' << vr << ' '<< l << ' ' << r << ' ' << K << ' ' << B << ' ' << t[v] << '\n';

//    cout << k[v] << ' ' << b[v] << '\n';
    push( v , vr - vl + 1 );

//    cout << v << ' ' << vl << ' ' << vr << ' '<< l << ' ' << r << ' ' << K << ' ' << B << ' ' << t[v] << '\n';

    if( vl > r || vr < l )
    {
//        cout << "?\n";
        return;
    }

    if( vl >= l && vr <= r )
    {
//        cout << "!\n";
        k[v] *= K;
        b[v] += B;

        push( v , vr - vl + 1 );

//        cout << t[v] << '\n';

        return;
    }

    int mid = ( vl + vr ) / 2;

    upd( v * 2 , vl , mid , l , r , K , B );
    upd( v * 2 + 1 , mid + 1 , vr , l , r , K , B );

//    cout << v << ' ' << t[v * 2]  << ' ' << t[v * 2 + 1] << '\n';

    t[v] = t[v * 2] + t[v * 2 + 1];

//    cout << t[v] << '\n';
}

ld get( int v , int vl , int vr , int l , int r )
{
    push( v , vr - vl + 1 );

    if( vl > r || vr < l )
    {
        return 0;
    }

    if( vl >= l && vr <= r )
    {
        return t[v];
    }


    int mid = ( vl + vr ) / 2;

    return get( v * 2 , vl , mid , l , r ) + get( v * 2 + 1 , mid + 1 , vr , l , r );
}


void solve()
{
    int n , q;
    cin >> n >> q;

    int a[n];

    while( st < n )
    {
        st *= 2;
    }

    fill( k , k + st * 2 , 1.0 );

    for( int i = 0;i < n;++ i )
    {
        cin >> a[i];

        upd( 1 , 0 , st - 1 , i , i , 0.0 , ld( a[i] ) );
    }

    while( q -- )
    {
        int T;
        cin >> T;

        if( T == 1 )
        {
            int l1 , r1 , l2 , r2;
            cin >> l1 >> r1 >> l2 >> r2;

            -- l1 , -- r1 , -- l2 , -- r2;

            ld b2 = get( 1 , 0 , st - 1 , l2 , r2 );
            ld b1 = get( 1 , 0 , st - 1 , l1 , r1 );

            int sz1 = r1 - l1 + 1 , sz2 = r2 - l2 + 1;


            upd( 1 , 0 , st - 1 , l1 , r1 , 1.0 - ( 1.0 / sz1 ) , (ld)b2 / (ld)sz2 / (ld)sz1 );
            upd( 1 , 0 , st - 1 , l2 , r2 , 1.0 - ( 1.0 / sz2 ) , (ld)b1 / (ld)sz1 / (ld)sz2 );

        }
        else
        {
            int l , r;
            cin >> l >> r;

            -- l , -- r;

            cout << fixed << setprecision( 6 ) << get( 1 , 0 , st - 1 , l , r ) << '\n';
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

