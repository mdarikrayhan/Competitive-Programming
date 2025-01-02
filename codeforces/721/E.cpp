// LUOGU_RID: 157778855
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=4e5+10;
int L2,n,p,t,ans;
int l,r,Max,L,R=-1;
pii Q[N];
priority_queue<pii,vector<pii>,greater<pii>>q;
int main()
{
    scanf("%d%d%d%d",&L2,&n,&p,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l,&r);
        while(q.size()&&q.top().fi<=r-t)
        {
            pii t2=q.top();q.pop();
            ans=max(ans,t2.se);
            if(L<=R&&Q[R].se+(t2.fi-Q[R].fi)/p<t2.se)R--;
            Q[++R]=t2;
        }
        while(L<=R&&Q[L].fi<l-t)Max=max(Max,Q[L].se),L++;
        int p2=(r-l)/p*p+l;
        q.push({p2,Max+(r-l)/p});
        if(L<=R){
            p2=Q[L].fi+t+(r-Q[L].fi-t)/p*p;
            q.push({p2,Q[L].se+(r-Q[L].fi-t)/p});
        }
    }
    while(!q.empty())ans=max(ans,q.top().se),q.pop();
    printf("%d",ans);
    return 0;
}