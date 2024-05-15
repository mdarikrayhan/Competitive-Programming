#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string st;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define nl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define elif else if
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
//transform( S.begin(), S.end(), S.begin(), ::toupper );

void sieve( ll n )
{
    ll i, j, x=sqrt(n);
    vll vis(n+1, 1), prime;
    vis[0]=vis[1]=0;
    //prime.pb(2);
    for( i=4; i<=n; i+=2 )vis[i]=0;

    for( i=3; i<=x; i+=2 )
    {
        if( vis[i] )
        {
            //prime.pb(i);
            for( j=i+i; j<=n; j+=i )vis[j]=0;
        }
    }

}


int main()
{
    optimize();

    ll i, j, t, n, m, k;
    cin>>t;
    while( t-- )
    {
        cin>>n;
        ll a=0, b=0; k=0;
        for( i=1; i<=n; i++ )
        {
            cin>>j;
            if( j==1 )
            {
                b++;
            }
            else
            {
                a+=b;
                b=0;
            }
            if( a )k = max( k, b+(a+2)/2 );
            else k = max( k, b );
        }
        cout<<k<<nl;
    }

    return 0;
}
