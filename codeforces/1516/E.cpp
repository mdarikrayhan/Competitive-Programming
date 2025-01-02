#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const int inf=INT_MAX;
const int maxn=410;
const int md=1e9+7;

int modInv(int a, int m)
{
    int m0=m;
    int y=0, x=1;
    if(m==1)
        return 0;
    while(a>1)
    {
        int q=a/m;
        int t=m;
        m=a%m, a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
        x+=m0;
    return x;
}

int inv[maxn];
int fac[maxn], inv_fac[maxn];

int n, k;

int prod[maxn]; // prod[i] é n * (n - 1) * ... * (n - i + 1)
int invprod[maxn];

int dp[maxn][maxn]; // dp[i][j] - i ciclos maiores que 1 e o resto tudo 1, a ordem importa, a soma dos tamanhos deles é j

int ans[maxn];

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    ios::sync_with_stdio(0);cin.tie(0);

    fac[0]=1, inv_fac[0]=1;
    for(int i=1; i<maxn; i++)
        fac[i]=(ll)fac[i-1]*i%md;
    inv_fac[maxn-1]=modInv(fac[maxn-1], md);
    for(int i=maxn-2; i>=1; i--)
        inv_fac[i]=(ll)inv_fac[i+1]*(i+1)%md;
    inv[1]=1;
    for(int i=2; i<maxn; i++)
        inv[i]=(ll)(md-md/i)*inv[md%i]%md;

    cin>> n>> k;
    prod[0]=1;
    for(int i=1; i<maxn; i++) prod[i] = prod[i-1] * (n-i+1) % md;
    for(int i=0; i<maxn; i++) invprod[i] = modInv(prod[i], md);
    dp[0][0] = 1;
    for(int i=1; i<=200; i++)
    {
        for(int j=2*i; j<=i+200; j++)
        {
            for(int t=2; t<=j; t++)
            {
                dp[i][j] += dp[i-1][j-t] * prod[j] % md * invprod[j-t] % md * inv[t] % md; if(dp[i][j] >= md) dp[i][j] -= md;
            }
        }
    }
    for(int i=0; i<=200; i++)
    {
        for(int j=2*i; j<=i+200; j++)
        {
            dp[i][j] = dp[i][j] * inv_fac[i] % md;
        }
    }
    for(int j=0; j<=k; j++)
    {
        // exatamente j swaps => n - j ciclos => x de tamanho > 1 com soma j + x
        for(int x=0; x<=j; x++)
        {
            ans[j] += dp[x][j+x]; if(ans[j] >= md) ans[j] -= md;
        }
    }
    for(int j=1; j<=k; j++)
    {
        ans[j] += (j >= 2 ? ans[j-2] : 0); if(ans[j] >= md) ans[j] -= md;
        cout<< ans[j]<< " ";
    }
    cout<< "\n";

    return 0;
}