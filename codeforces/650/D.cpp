// LUOGU_RID: 160149421
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define ll long long
#define pr pair<int,int>
using namespace std;
const int maxn=4e5+10,A=1e9,p=998244353;
int n,m,a[maxn],cnt;
pr L[maxn],R[maxn],LIS;
struct qur{int x,y,id,ans;}b[maxn];
bool cmp1(qur X,qur Y){return X.x<Y.x;}
bool cmp2(qur X,qur Y){return X.id<Y.id;}
struct node
{
    int ls,rs;
    pr dat;
    void cl(){ls=rs=dat.first=dat.second=0;}
}t[maxn<<4];
int new_node()
{
    t[++cnt].cl();
    return cnt;
}
pr operator + (pr X,pr Y)
{
    if(X.first<Y.first) return Y;
    if(X.first>Y.first) return X;
    return make_pair(X.first,(X.second+Y.second)%p);
}
void upd(int id)
{
    if(t[id].ls==0&&t[id].rs==0) return;
    t[id].dat=make_pair(0,0);
    if(t[id].ls) t[id].dat=t[id].dat+t[t[id].ls].dat;
    if(t[id].rs) t[id].dat=t[id].dat+t[t[id].rs].dat;
}
void modify(int l,int r,int id,int loc,pr X)
{
    if(l==r)
    {
        t[id].dat=(t[id].dat+X);
        return;
    }
    int mid=(l+r)>>1;
    if(loc<=mid)
    {
        if(!t[id].ls) t[id].ls=new_node();
        modify(l,mid,t[id].ls,loc,X);
    }
    else
    {
        if(!t[id].rs) t[id].rs=new_node();
        modify(mid+1,r,t[id].rs,loc,X);
    }
    upd(id);
}
pr query(int l,int r,int id,int nl,int nr)
{
    if(id==0||t[id].dat.first==0||nl>nr) return make_pair(0,0);
    if(nl<=l&&r<=nr) return t[id].dat;
    int mid=(l+r)>>1;
    if(nl<=mid&&mid<nr) return query(l,mid,t[id].ls,nl,nr)+query(mid+1,r,t[id].rs,nl,nr);
    if(nl<=mid) return query(l,mid,t[id].ls,nl,nr);
    return query(mid+1,r,t[id].rs,nl,nr);
}
bool F(int loc)
{
    if(L[loc].first+R[loc].first-1!=LIS.first) return 0;
    return 1ll*L[loc].second*R[loc].second%p==LIS.second;
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y),b[i].id=i;
	sort(b+1,b+m+1,cmp1),cnt=0,new_node();
	int loc=1;
	for(int i=1;i<=n;i++)
    {
        while(loc<=m&&b[loc].x==i)
        {
            pr tmp=query(1,A,1,1,b[loc].y-1);
            b[loc++].ans+=tmp.first;
        }
        L[i]=query(1,A,1,1,a[i]-1),L[i].first++,L[i].second=max(L[i].second,1),modify(1,A,1,a[i],L[i]);
    }
    loc=m,cnt=0,new_node();
    for(int i=n;i>=1;i--)
    {
        while(loc>=1&&b[loc].x==i)
        {
            pr tmp=query(1,A,1,b[loc].y+1,A);
            b[loc--].ans+=tmp.first;
        }
        R[i]=query(1,A,1,a[i]+1,A),R[i].first++,R[i].second=max(R[i].second,1),modify(1,A,1,a[i],R[i]);
    }
    LIS=query(1,A,1,1,A);
    for(int i=1;i<=m;i++) b[i].ans=max(b[i].ans+1,(F(b[i].x)?(LIS.first-1):LIS.first));
    sort(b+1,b+m+1,cmp2);
    for(int i=1;i<=m;i++) printf("%d\n",b[i].ans);
	return 0;
}