//Dedicated to my love,ivaziva
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dbg(x) cerr<<#x<<": "<<x<<endl;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double

const ll inf=(ll)1e18+5;
const int mod=1e9+7;
const int K=501;
const int L=11;
const int N=3e5+2;

ll readint()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,q;
vector<pair<int,pii>> que;
bool check(int x)
{
    vector<vector<int>> v(501,vector<int>(501,0));
    for(int i=0;i<=x;i++) v[que[i].se.fi][que[i].se.se]=1;
    vector<vector<int>> ps(501,vector<int>(501,0));
    ps[1][1]=v[1][1];
    for(int i=1;i<=n;i++) ps[i][1]=ps[i-1][1]+v[i][1];
    for(int i=1;i<=m;i++) ps[1][i]=ps[1][i-1]+v[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+v[i][j];
        }
    }
    for(int i=k;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
        {
            int fr=i-k+1,tr=i,fc=j-k+1,tc=j;
            int qry=ps[tr][tc]-ps[fr-1][tc]-ps[tr][fc-1]+ps[fr-1][fc-1];
            if(qry==k*k) return 1;
        }
    }
    return 0;
}
int main()
{
    n=readint();m=readint();k=readint();q=readint();
    for(int i=1;i<=q;i++)
    {
        int x,y,t;
        x=readint();y=readint();t=readint();
        que.pb({t,{x,y}});
    }
    sort(que.begin(),que.end());
    int lb=0,rb=q-1;
    int ans=-1;
    while(lb<=rb)
    {
        int mid=lb+rb>>1;
        if(check(mid))
        {
            rb=mid-1;
            ans=mid;
        }
        else lb=mid+1;
    }
    if(ans==-1)
    {
        printf("%d\n",ans);
        return 0;
    }
    printf("%d\n",que[ans].fi);
    return 0;
}
