#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fo(i,n) for(i=0;i<n;i++)
using namespace std;
 
ll mod = 1e9+7;
ll inf = 1e18;
 
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
ll m,d,n;
string l,r;
ll memo[2005][2][2][2005];

ll dp(ll lvl,ll lo,ll hi,ll rem)
{
    if(lvl==n)
    {
        if(rem==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(memo[lvl][lo][hi][rem]!=-1)
    {
        return memo[lvl][lo][hi][rem];
    }
    memo[lvl][lo][hi][rem]=0;
    int lolim=0;
    int hlim=9;
    if(lo==1)
    {
        lolim=l[lvl]-'0';
    }
    if(hi==1)
    {
        hlim=r[lvl]-'0';
    }
    if(lvl%2==1)
    {
        if(d>=lolim && d<=hlim )
        {
            int nhi=0;
            int nlo=0;
            if(d==lolim && lo==1)
            {
                nlo=1;
            }
            if(d==hlim && hi==1)
            {
                nhi=1;
            }
            memo[lvl][lo][hi][rem]=(memo[lvl][lo][hi][rem]+dp(lvl+1,nlo,nhi,(rem*10+d)%m))%mod;
        }
    }
    if(lvl%2==0)
    {
        for(int i=lolim;i<=hlim;i++)
        {
            int nhi=0;
            int nlo=0;
            if(i!=d)
            {
                if(i==lolim && lo==1)
                {
                    nlo=1;
                }
                if(i==hlim && hi==1)
                {
                    nhi=1;
                }
                memo[lvl][lo][hi][rem]=(memo[lvl][lo][hi][rem]+dp(lvl+1,nlo,nhi,(rem*10+i)%m))%mod;
            }
        }
    }
    return memo[lvl][lo][hi][rem];
}

void solve()
{   //cout<<setprecision(13); 
    memset(memo,-1, sizeof(memo));
    cin>>m>>d;
    cin>>l;
    cin>>r;
    n=l.size();
    cout<<dp(0,1,1,0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    //int tc;
    //cin>>tc;
    //while(tc--)
    solve();
    return 0;
}