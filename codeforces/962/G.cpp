#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
using namespace std;
struct node
{
    int x,l,r;
    node(){}
    node(int X,int L,int R)
    {
        x=X;l=L;r=R;
    }
}a[30000+5];
struct point{int x,y;}b[30000+5];
vector<pair<int,int> >p[15000+5];
int vis[30000+5],num;
void rev(int x)
{
    num-=vis[x];
    vis[x]^=1;
    num+=vis[x];
}
int main()
{
    int n,xl,xr,u,d,i,j,k,m=0,ans=0,tot=0;
    scanf("%d%d%d%d",&xl,&u,&xr,&d);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d%d",&b[i].x,&b[i].y);
    b[n+1]=b[1];
    for (i=1;i<=n;i++)
        if (b[i].x==b[i+1].x)
            a[++m]=node(b[i].x,b[i].y,b[i+1].y);
    n=15000;
    for (i=1;i<=m;i++)
        p[a[i].x].push_back(make_pair(a[i].l,a[i].r));
    for (i=0;i<xr;i++)
    {
        for (j=0;j<p[i].size();j++)
        {
            int L=p[i][j].first,R=p[i][j].second;
            int l=min(L,R),r=max(L,R);
            l=max(l,d);r=min(r,u);
       //     printf("%d : %d ~ %d\n",i,l,r);
            if (l>r) continue;
            int las=num;
            rev(l);rev(r);
            if (i>xl&&L>R) ans+=(num-las)>>1;//printf("## %d %d\n",num,las);
        }
        if (i==xl) ans=num>>1;//printf("## %d -1\n",num);
    }
    printf("%d\n",ans);
}