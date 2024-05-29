// LUOGU_RID: 160038184
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2010,V=2000,M=1e5+10,INF=0x3f3f3f3f3f3f3f3f;
int n,m,ans,tot,cnt,up[N][N],dn[N][N],l[N][N],r[N][N];char s[N][N];
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
    inline bool chk(char c) { return !(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'||c=='.'||c=='#'); }
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
    n=read(),m=read();for(int i=1,l=0;i<=n;i++) rd(s[i],l),l=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        up[i][j]=up[i-1][j]|(s[i][j]=='#');
        l[i][j]=l[i][j-1]|(s[i][j]=='#');
    }
    for(int i=n;i>=1;i--) for(int j=m;j>=1;j--)
    {
        dn[i][j]=dn[i+1][j]|(s[i][j]=='#');
        r[i][j]=r[i][j+1]|(s[i][j]=='#');
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        up[i][j]^=1,dn[i][j]^=1,l[i][j]^=1,r[i][j]^=1;
    for(int i=2;i<n;i++) ans+=r[i][1];for(int j=2;j<m;j++) ans+=dn[1][j];
    for(int i=2;i<n;i++) for(int j=2;j<m;j++) ans+=(l[i][j]+r[i][j])*(dn[i][j]+up[i][j]);
    for(int j=2;j<m;j++,tot=0,cnt=0) for(int i=2;i<n;i++)
    {
        if(l[i][j]) ans+=tot+cnt+(i>2&&r[i-1][j]);
        if(r[i][j]) ans+=tot+cnt+(i>2&&l[i-1][j]);
        if(i>2) tot+=l[i-1][j],cnt+=r[i-1][j];
        if(s[i][j]=='#') tot=0,cnt=0;
    }tot=0,cnt=0;
    for(int i=2;i<n;i++,tot=0,cnt=0) for(int j=2;j<m;j++)
    {
        if(up[i][j]) ans+=tot+cnt+(j>2&&dn[i][j-1]);
        if(dn[i][j]) ans+=tot+cnt+(j>2&&up[i][j-1]);
        if(j>2) tot+=up[i][j-1],cnt+=dn[i][j-1];
        if(s[i][j]=='#') tot=0,cnt=0;
    }
    print(ans);genshin:;flush();return 0;
}