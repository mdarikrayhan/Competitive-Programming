// LUOGU_RID: 156104625
#include<bits/stdc++.h>
#define LL __int128
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=110,M=6e6,mod=998244353;
const ll RM=(1ll<<60)-1;
int na,nb,cnt;
vector<pll>tmpa[N],tmpb[N];
vector<pll>resa[N][61],resb[N][61];
pll stk[M];
LL ans;
#define mid (l+r)/2
void get(ll l,ll r,ll lp,ll rp,int op,int t)
{
    if(lp<=l&&r<=rp){
        ll x=r-l+1;int cnt=0;
        while(x>1)x/=2,cnt++;
        if(op==0)resa[t][cnt].push_back({l,r});
        else resb[t][cnt].push_back({l,r});
        return;
    }
    if(lp<=mid)get(l,mid,lp,rp,op,t);
    if(rp>mid)get(mid+1,r,lp,rp,op,t);
}
LL calc(ll l,ll r){
    return (LL)(l+r)*(r-l+1)/2;
}
ll minva[N],minvb[N];
ll maxva[N],maxvb[N];
int main()
{
    // freopen("4.in","r",stdin);
    // freopen("4.out","w",stdout);
    scanf("%d",&na);
    for(int i=1;i<=na;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        minva[i]=l;maxva[i]=r;
        get(0,RM,l,r,0,i);
    }
    scanf("%d",&nb);
    for(int i=1;i<=nb;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        minvb[i]=l;maxvb[i]=r;
        get(0,RM,l,r,1,i);
    }
    for(int a=1;a<=na;a++)
    for(int b=1;b<=nb;b++){
        for(int i=60;i>=0;i--)
        if(resa[a][i].size())
        {
            for(pll t:resa[a][i])
            for(pll t2:resb[b][i]){
                ll x=(t.se^t.fi)|(t2.se^t2.fi),y=(t.fi^t2.fi);
                ll L2=y-(x&y),R2=y|x;
                stk[++cnt]={L2,R2};
            }
            for(pll t:resa[a][i])
            {
                ll x=(t.se^t.fi),y=(t.fi^minvb[b]);
                ll L2=y-(x&y),R2=y|x;
                stk[++cnt]={L2,R2};
            }
            for(pll t:resa[a][i])
            {
                ll x=(t.se^t.fi),y=(t.fi^maxvb[b]);
                ll L2=y-(x&y),R2=y|x;
                stk[++cnt]={L2,R2};
            }
        }
        for(int i=60;i>=0;i--)
        if(resb[b][i].size())
        {
            for(pll t:resb[b][i])
            {
                ll x=(t.se^t.fi),y=(t.fi^minva[a]);
                ll L2=y-(x&y),R2=y|x;
                stk[++cnt]={L2,R2};
            }
            for(pll t:resb[b][i])
            {
                ll x=(t.se^t.fi),y=(t.fi^maxva[a]);
                ll L2=y-(x&y),R2=y|x;
                stk[++cnt]={L2,R2};
            }
        }
    }
    sort(stk+1,stk+cnt+1);
    ll las=-1,L2=0,R2=-1;
    for(int i=1;i<=cnt;i++){
        pll t=stk[i];
        if(t.fi>R2){
            ans+=calc(L2,R2);
            L2=t.fi,R2=t.se;
        }
        else
            R2=max(R2,t.se);
    }
    ans+=calc(L2,R2);
    printf("%d",(int)(ans%mod));
    return 0;
}