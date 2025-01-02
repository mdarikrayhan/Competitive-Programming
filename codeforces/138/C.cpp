// LUOGU_RID: 160505805
#include <bits/stdc++.h>
#define ls (p<<1)
#define rs (ls|1)
#define mid ((l+r)>>1)
#define get(x) (lower_bound(b+1,b+1+tot,x)-b)
using namespace std;
const int N=1.2e5+10,mod=1e9+7,V=1e9,INF=0x3f3f3f3f3f3f3f3f;
int n,m,tot,b[N<<2],a[N],h[N],l[N],r[N],x[N],w[N];double t[N<<4],ans;
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
inline void modify(int p,int l,int r,int s,int e,int x)
{
    if(l>=s&&r<=e) return t[p]*=x*1.0/100,void();
    if(mid>=s) modify(ls,l,mid,s,e,x);if(mid<e) modify(rs,mid+1,r,s,e,x);
}
inline double query(int p,int l,int r,int x){if(l==r) return t[p];return ((mid>=x)?query(ls,l,mid,x):query(rs,mid+1,r,x))*t[p];}
signed main()
{
    n=read(),m=read();for(int i=1;i<=n;i++) a[i]=read(),h[i]=read(),l[i]=read(),r[i]=read();
    for(int i=1;i<=n;i++) b[++tot]=a[i]-h[i],b[++tot]=a[i]-1,b[++tot]=a[i]+1,b[++tot]=a[i]+h[i];
    for(int i=1;i<=m;i++) x[i]=read(),w[i]=read(),b[++tot]=x[i];
    sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;for(int i=1;i<=(tot<<2);i++) t[i]=1;
    for(int i=1;i<=n;i++) modify(1,1,tot,get(a[i]-h[i]),get(a[i]-1),100-l[i]),modify(1,1,tot,get(a[i]+1),get(a[i]+h[i]),100-r[i]);
    for(int i=1;i<=m;i++) ans+=query(1,1,tot,get(x[i]))*w[i];printf("%.9lf",ans);
    genshin:;flush();return 0;
}
