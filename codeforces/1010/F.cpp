// LUOGU_RID: 158330370
#include<bits/stdc++.h>
#define N 200010
#define mod 998244353
#define ve vector<int>
#define pvv pair<ve,ve>
#define fi first
#define se second
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Down(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
int n,sz[N],son[N],g[N],h[N],fac[N],upw[N],anc[N];
int w[20][N],iw[20][N],pos[N],invlen,invf[N];
long long m;
ve go[N],f[N],a[N],b[N];
inline void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline int addm(int x,int y){x+=y;return x>=mod?x-mod:x;}
inline int subm(int x,int y){x-=y;return x<0?x+mod:x;}
inline int read()
{
    register int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

inline int fpow(int a,int b)
{
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mod)
        if(b&1) res=1ll*res*a%mod;
    return res;
}

inline void prework()
{
    For(i,1,18)
    {
        int x=fpow(3,(mod-1)/(1<<i));
        int y=fpow(x,mod-2);w[i][0]=iw[i][0]=1;
        For(j,1,(1<<i-1))
        {
            w[i][j]=1ll*w[i][j-1]*x%mod;
            iw[i][j]=1ll*iw[i][j-1]*y%mod;
        }
    }
    return;
}

inline void NTT(int *f,int len,int flag)
{
    For(i,1,len-2) if(i < pos[i]) swap(f[i],f[pos[i]]);
    for(int l=2,b=1;l<=len;l<<=1,b++)
        for(int i=0;i<len;i+=l) For(j,i,i+(l>>1)-1)
        {
            int g=f[j],h=1ll*f[j|(l>>1)]*(flag?w[b][j-i]:iw[b][j-i])%mod;
            f[j]=addm(g,h),f[j|(l>>1)]=subm(g,h);
        }
    if(!flag) For(i,0,len-1) f[i]=1ll*f[i]*invlen%mod;
    return;
}

inline ve add(ve a,ve b)
{
    ve c;
    int n=a.size(),m=b.size();
    int lim=max(n,m)-1;
    For(i,0,lim) c.push_back(0);
    For(i,0,n-1) add(c[i],a[i]);
    For(i,0,m-1) add(c[i],b[i]);
    return c;
}

inline ve up(ve a)
{
    ve c;c.push_back(0);
    for(int x:a) c.push_back(x);
    return c;
}

inline ve mul(ve a,ve b)
{
    ve c;
    int n=a.size(),m=b.size();
    int lim=n+m-2,len=1;
    while(len < lim+1) len<<=1;
    invlen=fpow(len,mod-2);
    For(i,1,len-2) pos[i]=pos[i>>1]>>1|(i&1?len>>1:0);
    For(i,0,n-1) g[i]=a[i];
    For(i,0,m-1) h[i]=b[i];
    For(i,n,len) g[i]=0;
    For(i,m,len) h[i]=0;
    NTT(g,len,true),NTT(h,len,true);
    For(i,0,len-1) g[i]=1ll*g[i]*h[i]%mod;
    NTT(g,len,false);
    For(i,0,lim) c.push_back(g[i]);
    return c;
}

inline void dfs(int x,int fa)
{
    sz[x]=1,anc[x]=fa;
    for(int to:go[x]) if(to^fa)
    {
        dfs(to,x),sz[x]+=sz[to];
        if(sz[to] > sz[son[x]]) son[x]=to;
    }
    return;
}

inline pvv calc(int l,int r)
{
    if(l == r) return pvv(a[l],a[l]);
    int mid=l+r>>1;
    pvv nl=calc(l,mid),nr=calc(mid+1,r);
    return pvv(add(nl.fi,mul(nl.se,nr.fi)),mul(nl.se,nr.se));
}

inline void solve(int x)
{
    if(!son[x]) {f[x]=ve{1,1};return;}
    for(int i=x;i;i=son[i]) for(int to:go[i]) 
        if(to^son[i] && to^anc[i]) solve(to);
    int cnt=0;
    for(int i=x;i;i=son[i]) 
    {
        a[++cnt]=ve{0,1};
        for(int to:go[i]) if(to^son[i] && to^anc[i]) 
            a[cnt]=up(f[to]),f[to].clear();
    }pvv nw=calc(1,cnt-1);
    f[x]=add(ve{1},add(nw.fi,up(nw.se)));
    return;
}

int main()
{
    n=read(),scanf("%lld",&m),m=(m+1)%mod;
    For(i,1,n-1)
    {
        int x=read(),y=read();
        go[x].push_back(y);
        go[y].push_back(x);
    }prework(),fac[0]=upw[0]=1;
    For(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
    invf[n]=fpow(fac[n],mod-2);
    Down(i,n-1,0) invf[i]=1ll*invf[i+1]*(i+1)%mod;
    For(i,1,n) upw[i]=1ll*upw[i-1]*(m+i-1)%mod;
    dfs(1,0),solve(1);
    int ans=f[1][0]-1;
    For(i,1,n) 
    {
        int coef=1ll*upw[i-1]*invf[i-1]%mod;
        add(ans,1ll*coef*f[1][i]%mod);
    }printf("%d\n",ans);
    return 0;
}
