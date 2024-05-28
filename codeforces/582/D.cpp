// LUOGU_RID: 160513297
#include<bits/stdc++.h>
#define maxn 3510
#define P 1000000007
using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
ll n,p,a,len,ans;
int t[maxn],f[maxn][maxn][2][2];
ll lim[maxn];
char s[maxn];
int main()
{
    read(p),read(a),scanf("%s",s+1),len=strlen(s+1);
    for(int i=1;i<=len;++i) t[i]=s[len-i+1]-'0';
    while(len)
    {
        ll v=0;
        for(int i=len;i>=1;--i)
        {
            v=v*10+t[i],t[i]=v/p,v%=p;
            if(!t[i]&&i==len) len--;
        }
        lim[++n]=v;
    }
    f[n+1][0][1][0]=1;
    for(int i=n;i>=1;--i)
    {
        ll v1=(p+1)*p/2%P;
        ll v2=(lim[i]+1)*lim[i]/2%P;
        ll v3=p*(p-1)/2%P;
        ll v4=lim[i]*(2*p-lim[i]-1)/2%P;
        ll v5=lim[i]*(lim[i]-1)/2%P;
        ll v6=lim[i]*(2*p-lim[i]+1)/2%P;
        for(int j=0;j<=n-i;++j)
        {
            ll f1=f[i+1][j][0][0],f2=f[i+1][j][1][0],f3=f[i+1][j][0][1],f4=f[i+1][j][1][1];
            f[i][j][0][0]=(f1*v1%P+f2*v2%P+f3*v3%P+f4*v4%P)%P;
            f[i][j][1][0]=(f2*(lim[i]+1)%P+f4*(p-1-lim[i])%P)%P;
            f[i][j+1][0][1]=(f1*v3%P+f2*v5%P+f3*v1%P+f4*v6%P)%P;
            f[i][j+1][1][1]=(f2*lim[i]%P+f4*(p-lim[i])%P)%P;
        }
    }
    for(int i=a;i<=n;++i) ans=(ans+f[1][i][0][0]+f[1][i][1][0])%P;
    printf("%lld",ans);
    return 0;
}
 