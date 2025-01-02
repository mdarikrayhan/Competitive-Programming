#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;


#define F		        first
#define S		        second
#define pb		        push_back
#define endl            '\n'
#define Mp              make_pair
#define all(x)          x.begin(), x.end()
#define debug(x)        cerr << #x << " = " << x << endl;
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io         freopen("tests.in" , "r" , stdin) ;

ll mod = 998244353 ;

const int N = 2e5+23, MP=19, M=36;

ll a[N], base[M];
ll ans[M], pw;
ll dp[2][M][1<<MP];
int sz;

int n, m;

int main()
{
    fast_io
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>a[i];
        for (int j=0; j<m; j++) if(a[i]>>j&1) a[i]^=base[j];
        if(!a[i]) continue;
        sz++;
        int k=__builtin_ctzll(a[i]);
        base[k]=a[i];
        for (int j=0; j<m; j++) if(j!=k && base[j]>>k&1) base[j]^=base[k];
    }
    pw=1;
    vector<ll> A, B;
    for (int i=0; i<m; i++) if(base[i]) A.pb(base[i]);
    for (int i=0; i<n-sz; i++) pw=pw*2%mod;
    if(sz<=18){
        for (int mask=0; mask<(1<<sz); mask++){
            ll xo=0;
            for (int i=0; i<sz; i++) if(mask>>i&1) xo^=A[i];
            ans[__builtin_popcountll(xo)]++;
        }
        for (int i=0; i<=m; i++) cout<<ans[i]*pw%mod<<" ";
        return cout<<endl, 0;
    }

    for (int i=0; i<sz; i++) B.pb(0);
    for(int i=0; i<m; i++)if(!base[i])for (int j=0; j<sz; j++)B[j]=B[j]*2+(A[j]>>i&1);

    dp[1][0][0]=1;
    for (int i=0; i<sz; i++){
        for (int j=0; j<=i+1; j++){
            for (int mask=0; mask<(1<<(m-sz)); mask++){
                dp[i&1][j][mask]=dp[1-i&1][j][mask];
                if(j) dp[i&1][j][mask]=(dp[i&1][j][mask]+dp[1-i&1][j-1][mask^B[i]])%mod;
            }
        }
    }
    for (int i=0; i<=sz; i++)for (int mask=0; mask<(1<<(m-sz)); mask++) ans[__builtin_popcountll(mask)+i]=(ans[__builtin_popcountll(mask)+i]+dp[1-sz&1][i][mask])%mod;

    for (int i=0; i<=m; i++) cout<<ans[i]*pw%mod<<" ";

    cout<<endl;

}
