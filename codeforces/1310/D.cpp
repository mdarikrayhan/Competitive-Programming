// LUOGU_RID: 159814259
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=85,V=15,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
int n,k,T=3000,ans=INF,a[N],d[N][N],f[V][N];mt19937 rnd(time(NULL));
namespace Fast_IO
{
    static char buf[1000000],*paa=buf,*pd=buf,out[10000000];int length=0;
    #define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
    inline int read()
    {
        int u(0),t(1);char fc(getchar());
        while(!isdigit(fc)){if(fc=='-') t=-1;fc=getchar();}
        while(isdigit(fc)) u=(u<<1)+(u<<3)+(fc^48),fc=getchar();
        return u*t;
    }
    inline void flush(){fwrite(out,1,length,stdout);length=0;}
    inline void put(char c){if(length==9999999) flush();out[length++]=c;}
    inline void put(string s){for(char c:s) put(c);}
    inline void print(int u)
    {
        if(u<0) put('-'),u=-u;
        if(u>9) print(u/10);
        put(u%10+'0');
    }
    inline bool chk(char c) { return !(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'); }
    inline bool ck(char c) { return c!='\n'&&c!='\r'&&c!=-1&&c!=' '; }
    inline void rd(char s[],int&n)
    {
        s[++n]=getchar();
        while(chk(s[n])) s[n]=getchar();
        while(ck(s[n])) s[++n]=getchar();
        n--;
    }
}
using namespace Fast_IO;
signed main()
{
    n=read(),k=read();for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=read();
    while(T--)
    {
        for(int i=1;i<=n;i++) a[i]=rnd()&1;memset(f,0x3f,sizeof f);f[0][1]=0;
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++)
                for(int u=1;u<=n;u++)
                    if(a[j]!=a[u]) f[i+1][u]=min(f[i+1][u],f[i][j]+d[j][u]);
        ans=min(ans,f[k][1]);
    }print(ans);
    genshin:;flush();return 0;
}