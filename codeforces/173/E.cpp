#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 100005
#define Fi(x) lower_bound(id+1,id+1+n,x,cmp2)-id
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t==1?x:-x;
}
struct node
{
    int x,y,idx;
}a[maxn];
int n,m,Q;
int id[maxn],ind[maxn],lef[maxn],rig[maxn],b[maxn],smt[maxn<<2],ans[maxn];
vector<pair<pair<int,int>,int>>qry[maxn];
struct BIT
{
    int tree[maxn];
    void cha(int x,int y)
    {
        for(int i=x;i<=n;i+=i&-i)
            tree[i]+=y;
    }
    int fi(int x)
    {
        int ret=0;
        for(int i=x;i;i-=i&-i)
            ret+=tree[i];
        return ret;
    }
    int fi(int l,int r)
    {
        return fi(r)-fi(l-1);
    }
}bit;
bool cmp(node x,node y)
{
    return x.y<y.y;
}
bool cmp2(int x,int y)
{
    return a[x].x<a[y].x;
}
void build_tree(int pos,int l,int r)
{
    smt[pos]=-1;
    if(l==r)return;
    int mid=l+r>>1;
    build_tree(pos<<1,l,mid);
    build_tree(pos<<1|1,mid+1,r);
}
void cha(int pos,int l,int r,int x,int y)
{
    if(l==r)
        return smt[pos]=y,void();
    int mid=l+r>>1;
    if(x<=mid)
        cha(pos<<1,l,mid,x,y);
    else
        cha(pos<<1|1,mid+1,r,x,y);
    smt[pos]=max(smt[pos<<1],smt[pos<<1|1]);
}
int fi(int pos,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return smt[pos];
    int mid=l+r>>1,ret=-1;
    if(L<=mid)
        ret=max(ret,fi(pos<<1,l,mid,L,R));
    if(R>mid)   
        ret=max(ret,fi(pos<<1|1,mid+1,r,L,R));
    return ret;
}
signed main()
{
    n=re(),m=re();
    for(int i=1;i<=n;i++)
        a[i].x=re();
    for(int i=1;i<=n;i++)
        a[i].y=re();
    for(int i=1;i<=n;i++)
        a[i].idx=id[i]=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1,j=1;i<=n;i++)
    {
        while(a[i].y-a[j].y>m)j++;
        lef[i]=j;
    }
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&a[j].y-a[i].y<=m)j++;
        rig[i]=j-1;
    }
    for(int i=1;i<=n;i++)
        ind[a[i].idx]=i;
    sort(id+1,id+1+n,cmp2);
    for(int i=1,j=1;i<=n;i++)
    {
        int x=id[i];
        while(j<=n&&a[id[j]].x<=a[x].x)
        {
            bit.cha(id[j],1);
            j++;
        }
        b[i]=bit.fi(lef[x],rig[x]);
    }
    Q=re();
    for(int i=1;i<=Q;i++)
    {
        int x=ind[re()],y=ind[re()];
        if(x>y)
            swap(x,y);
        if(rig[x]<lef[y])
            ans[i]=-1;
        else
            qry[max(Fi(x),Fi(y))].push_back(make_pair(make_pair(lef[y],rig[x]),i));
    }
    build_tree(1,1,n);
    for(int i=n;i;i--)
    {
        cha(1,1,n,id[i],b[i]);
        for(auto j:qry[i])
            ans[j.second]=fi(1,1,n,j.first.first,j.first.second);
    }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
	  		 			    		  		  	   	 		 	