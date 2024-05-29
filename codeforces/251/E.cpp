#include<bits/stdc++.h>
#define P 1000000007
#define maxn 200005
#define ll long long
using namespace std;

int N,R,l[maxn],r[maxn],p[maxn],s[maxn],d[maxn],f[maxn];
vector<int>e[maxn];

void init()
{
scanf("%d",&N);
for(int i=1,u,v;i<N*2;i++)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
}

void dfs(int u,int fa)
{
s[u]=1;
for(auto v:e[u])if(v!=fa)
{
dfs(v,u),p[u]=p[v],s[u]+=s[v],d[u]=d[v]+1;
if(!l[u])l[u]=v;else r[u]=v;
}
if(r[u])p[u]=u,d[u]=0;
}

ll G(int,int);
int F(int u)
{
if(!u)return 1;
if(s[u]&1)return 0;
if(!p[u])return s[u]/2;
if(f[u]>-1)return f[u];
int w=p[u],x=l[w],y=r[w];
ll res=0;
auto renew=[&](int x,int y)
{
if(!r[y])
{
if(d[u]%2==0&&s[y]>1)res+=G(x,l[y]);
if(!p[y]&&d[y]<=d[u]&&(d[u]+d[y])%2==0)res+=F(x)*(d[u]-d[y]>=2?2:1);
}
else 
{
if(!p[l[y]]&&d[l[y]]<d[u]&&(d[u]+d[l[y]])%2)res+=G(x,r[y]);
if(!p[r[y]]&&d[r[y]]<d[u]&&(d[u]+d[r[y]])%2)res+=G(x,l[y]);
}
};
renew(x,y),renew(y,x);
return f[u]=res%P;
}

ll G(int u,int v)
{
if(!u||!v)return F(u+v);
if(r[u]||r[v])return 0;
if(l[u]&&l[v])return G(l[u],l[v]);
return F(l[u]+l[v]);
}

int calc()
{
int ma=0;
for(int i=1;i<=2*N;i++)if(e[i].size()>ma)ma=e[i].size(),R=i;
if(ma>3)return 0;
if(ma==1)return 1;
if(ma==2)return(1ll*N*(N-1)+2)%P;
ll ans=0;
dfs(R,0),memset(f,-1,sizeof(f));
for(int i=0;i<6;i++)
{
int x=i/2,y=(i+3)%6/2,z=3-x-y,u,v;
x=e[R][x],y=e[R][y],z=e[R][z],u=l[y],v=r[y];
(ans+=G(x,u)*G(z,v))%=P;
if(u||v)(ans+=G(x,v)*G(z,u))%=P;
}
return ans%P;
}

int main()
{
init();
printf("%d\n",calc()*2%P);
return 0;
}