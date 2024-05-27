// LUOGU_RID: 160333113
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,V=1e5+10,M=24,mod=1004535809,p=13331;
int n,m,op[N],h[27][N];char s[N];vector<int>a,b;
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
inline int hsh(int i,int x,int l){return (h[i][x+l-1]-h[i][x-1]*op[l]%mod+mod)%mod;}
signed main()
{
    read(),m=read();rd(s,n);for(int i=op[0]=1;i<=n;i++) op[i]=op[i-1]*p%mod;
    for(int j='a';j<='z';j++) for(int i=1;i<=n;i++) h[j-'a'][i]=h[j-'a'][i-1]*p%mod+(s[i]==j);
    for(int i=1,x,y,l;i<=m;i++)
    {
        x=read(),y=read(),l=read();int f=0;a.clear();b.clear();
        for(int j='a';j<='z';j++) a.emplace_back(hsh(j-'a',x,l)),b.emplace_back(hsh(j-'a',y,l));
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        for(int j=0;j<a.size();j++) f|=(a[j]!=b[j]);
        put(f?"NO\n":"YES\n");
    }
    genshin:;flush();return 0;
}