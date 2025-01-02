#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define F first
#define S second
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Ok(x) x == true ?cout<<"Yes"<<endl : cout<<"No"<<endl;
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e5 + 3;
const int M = 998244353;
const int LOG = 30;
const ll INF = 1e18;
/////////////////////////////////////
int llg[N] ;
int st_maxC[LOG][N];
int st_maxD[LOG][N];
void pre ()
{
    // run it before test cases
    for (int x = 2; x < N; x++)
    {
        llg[x] = 1 + llg[x / 2];
    }
}
void buildSparceMxC( vector < int >A, int n )
{
    for (int i = 0; i < n; i++)
    {
        st_maxC[0][i] = A[i];
    }

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            st_maxC[i][j] = max(st_maxC[i - 1][j], st_maxC[i - 1][j + (1 << (i - 1))]);
        }
}
int get_maxC(int l, int r)
{
    l--;
    r--;
    int i = llg[r - l + 1];
    return max(st_maxC[i][l], st_maxC[i][r - (1 << i) + 1]);
}
void buildSparceMxD( vector < int >A, int n )
{
    for (int i = 0; i < n; i++)
    {
        st_maxD[0][i] = A[i];
    }

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            st_maxD[i][j] = max(st_maxD[i - 1][j], st_maxD[i - 1][j + (1 << (i - 1))]);
        }
}
int get_maxD(int l, int r)
{
    l--;
    r--;
    int i = llg[r - l + 1];
    return max(st_maxD[i][l], st_maxD[i][r - (1 << i) + 1]);
}
void Solve()
{
    pre();
    int n, c, d;
    cin >> n >> c >> d;
    vector < pair < int , int > > crr , drr;
    int bestC = 0, bestD = 0;
    for ( int i = 1 ; i <= n ; ++i )
    {
        int b, p ;
        char cc;
        cin >> b >> p >> cc;
        if ( cc == 'C' )
        {
            if ( p > c )continue;
            crr.push_back( { p , b } );
            bestC = max ( bestC , b );
        }
        else
        {
            if ( p > d )continue;
            drr.push_back ( { p , b } );
            bestD = max ( bestD , b );
        }
    }
    int ans = 0;
    if ( bestC > 0 and bestD > 0 )ans = bestC + bestD;
    sort ( crr.begin() , crr.end() );
    vector < int > v;
    for ( int i = 0 ; i < crr.size() ; i++ ){
        v.push_back( crr[i].S );
    }
    buildSparceMxC(v , v.size() - 1);
    sort ( drr.begin() , drr.end() );
    v.clear();
    for ( int i = 0 ; i < drr.size() ; i++ ){
        v.push_back( drr[i].S );
    }
    buildSparceMxD(v , v.size() - 1);
    for ( int i = 1 ; i < crr.size() ; i++ ){
        int rem = c - crr[i].F;
        pair < int , int > k = { rem , 2e9 };
        int ind = upper_bound( crr.begin() , crr.begin() + i , k ) - crr.begin();
        if ( ind < 1 )continue;
        int q = get_maxC( 1 , ind );
        ans = max ( ans , q + crr[i].S );
    }
    for ( int i = 1 ; i < drr.size() ; i++ ){
        int rem = d - drr[i].F;
        pair < int , int > k = { rem , 2e9 };
        int ind = upper_bound( drr.begin() , drr.begin() + i , k ) - drr.begin();
        if ( ind < 1 )continue;
        int q = get_maxD( 1 , ind );;
        ans = max ( ans , q + drr[i].S );
    }
    cout << ans << endl;
}
signed main()
{
    Fast;
    //freopen("input.txt","r",stdin );
    //freopen("output.txt","w",stdout);
    int Test = 1 ;
    ///cin >> Test;
    for(int test = 1 ; test <= Test ; test++ )
    {
        Solve();
    }
}
