// LUOGU_RID: 160057765
#include<bits/stdc++.h>
#define ls (lc[p])
#define rs (rc[p])
#define int long long
using namespace std;
const int N=1e5+10,V=1e5+10,M=1ll<<40,INF=0x3f3f3f3f3f3f3f3f;
int n,ans,tot,rt=1,lc[N<<6],rc[N<<6],a[N],s[N],p[N];
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
inline void insert(int&p,int w,int x)
{
    if(!p) p=++tot;if(!w) return ;
    if(w&x) insert(rs,w>>1,x);
    else insert(ls,w>>1,x);
}
inline int query(int p,int w,int x)
{
    if(!w) return 0;
    if(w&x)
    {
        if(ls!=0) return query(ls,w>>1,x)+w;
        return query(rs,w>>1,x);
    }
    if(rs!=0) return query(rs,w>>1,x)+w;
    return query(ls,w>>1,x);
}
signed main()
{
    n=read();for(int i=1;i<=n;i++) p[i]=p[i-1]^(a[i]=read());
    for(int i=n;i>=1;i--) s[i]=s[i+1]^a[i];tot++;
    for(int i=n;i>=0;i--) insert(rt,M,s[i+1]),ans=max(ans,query(1,M,p[i]));
    print(ans);
    genshin:;flush();return 0;
}