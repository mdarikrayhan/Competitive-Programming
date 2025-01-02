// LUOGU_RID: 160469601
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=55,M=2e4+30,mod=1e9+7,V=1e9,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,ans,f[N][M],a[N][M],s[N][M],g[M],b[M];
namespace Fast_IO
{
    static char buf[1000000],*paa=buf,*pd=buf,out[10000000];int length=0;
    #define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
    inline int read()
    {
        int x(0),t(1);char fc(getchar());
        while(!isdigit(fc)){if(fc=='-') t=-1;fc=getchar();}
        while(isdigit(fc)) x=(x<<1)+(x<<3)+(fc^48),fc=getchar();
        return x*t;
    }
    inline void flush(){fwrite(out,1,length,stdout);length=0;}
    inline void put(char c){if(length==9999999) flush();out[length++]=c;}
    inline void put(string s){for(char c:s) put(c);}
    inline void print(int x)
    {
        if(x<0) put('-'),x=-x;
        if(x>9) print(x/10);
        put(x%10+'0');
    }
    inline bool chk(char c) { return !(c=='<'||c=='>'||c=='#'||c=='^'||c=='v'); }
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
inline int ww(int i,int j){return s[i][j+k-1]-s[i][j-1];}
inline int get(int i,int x,int y)
{
    if(x<y) return s[i][x+k-1]-s[i][y-1];
    return s[i][y+k-1]-s[i][x-1];
}
signed main()
{
    n=read(),m=read(),k=read();for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
    for(int i=1;i<=n;i++) for(int j=1;j<=m+k;j++) s[i][j]=s[i][j-1]+a[i][j];
    for(int j=1;j<=m;j++) f[1][j]=ww(1,j)+ww(2,j),ans=max(ans,f[1][j]);
    for(int i=2;i<=n;i++)
    {
        memset(g,0,sizeof g);memset(b,0,sizeof b);
        for(int j=1;j<=m;j++) g[j]=max(g[j-1],f[i-1][j]);
        for(int j=m;j>=1;j--) b[j]=max(b[j+1],f[i-1][j]);
        for(int j=1;j<=m;j++)
        {
            int w=ww(i,j)+ww(i+1,j);f[i][j]=max(g[max(0ll,j-k)],b[j+k])+w;
            for(int l=max(1ll,j-k+1);l<=min(m-k+1,j+k-1);l++)
                f[i][j]=max(f[i-1][l]+w-get(i,j,l),f[i][j]);
            ans=max(ans,f[i][j]);
        }
    }print(ans);
    genshin:;flush();return 0;
}