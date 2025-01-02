// LUOGU_RID: 159077356
#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
int L[64],l,R[64],r;
char s[64];
int read(int a[],int &p,ll delta=0)
{
    scanf("%s",s); ll ans=0; for(int i=0;s[i];i++)
        ans=ans*16+(s[i]>'9'?s[i]-'a'+10:s[i]-'0');
    ans+=delta; p=(int)log2l(ans)/4+1;
    for(int i=0;i<p;i++) a[i]=(ans>>(p-i-1)*4)&15;
    return log2l(ans);
}
ll f[16][2][2]; int dfn[16][2][2],cur;
int V[16],len,D;
ll dfs(int p,bool flag,bool seen)
{
    if(p==len) return seen;
    ll &ans=f[p][flag][seen];
    if(dfn[p][flag][seen]==cur) return ans;
    ans=0; int R=flag?V[p]:15;
    for(int i=0;i<=R&&i<=D;i++)
        if(D/4!=len-p-1||((i>>(D&3))&1))
            ans+=dfs(p+1,flag&&i==R,seen||i==D);
    dfn[p][flag][seen]=cur; return ans;
}
void once()
{
    ll lv=read(L,l,-1),rv=read(R,r,0),ans=0;
    for(D=1;D<16&&D<=rv;D++) 
    {
        if(D<=lv)
        {
            memcpy(V,L,sizeof V), len=l;
            ++cur, ans-=dfs(0,1,0);
        }
        memcpy(V,R,sizeof V), len=r;
        ++cur, ans+=dfs(0,1,0);
    }
    printf("%lld\n",ans);
}
int main()
{
    int T; scanf("%d",&T);
    while(T--) once();
}