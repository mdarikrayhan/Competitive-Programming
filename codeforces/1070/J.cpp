// LUOGU_RID: 159039141
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,V=2e5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
int T,n,m,k,ans,cnt[N],f[N];char s[N];
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
    T=read();
    while(T--)
    {
        n=read(),m=read();read();k=0;rd(s,k);ans=INF;
        for(int i='A';i<='Z';i++) cnt[i]=0;
        for(int i=1;i<=k;i++) cnt[s[i]]++;
        for(int i='A';i<='Z';i++)
        {
            for(int j=0;j<=k;j++) f[j]=0;f[0]=1;
            for(int j='A';j<='Z';j++) if(i!=j) for(int l=k;l>=cnt[j];l--) f[l]|=f[l-cnt[j]];
            for(int j=max(0ll,n-cnt[i]);j<=k;j++)
                if(f[j])
                {
                    int h=max(0ll,n-j),r=max(0ll,m-(k-cnt[i]-j));
                    if(h+r<=cnt[i]) ans=min(ans,h*r);
                }
        }print(ans);put('\n');
    }
    genshin:;flush();return 0;
}