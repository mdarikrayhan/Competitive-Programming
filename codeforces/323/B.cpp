#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,INF=0x3f3f3f3f3f3f3f,mod=998244353;
int n,f,a[N][N];
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
    n=read();if(n==4){put("-1");goto genshin;}
    if(n&1) a[1][2]=a[2][3]=a[3][1]=1,f=3;
    else a[1][2]=a[2][3]=a[3][4]=a[4][1]=a[2][4]=a[3][1]=a[4][5]=a[5][3]=a[5][1]=a[2][5]=a[1][6]=a[3][6]=a[6][2]=a[4][6]=a[6][5]=1,f=6;
    for(int i=n;i>f;i-=2)
    {
        for(int j=1;j<=i-2;j++) a[j][i-1]=1,a[i][j]=1;
        a[i-1][i]=1;
    }
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) print(a[i][j]),put(' ');put('\n');}
    genshin:;flush();return 0;
}