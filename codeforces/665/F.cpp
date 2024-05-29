// LUOGU_RID: 159806127
#include<bits/stdc++.h>
#define N 1000010
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int pr[N],cnt,lim,m;
long long n,ans,v[N],f[N];
bool isp[N];
inline int get(long long x){return x<=lim?cnt-x+1:n/x;}
int main()
{
    scanf("%lld",&n);
    lim=sqrt(n),m=pow(n,1.0/3);
    memset(isp,true,sizeof(isp));
    For(i,2,lim) if(isp[i])
    {
        pr[++pr[0]]=i;
        for(int j=i<<1;j<=lim;j+=i) isp[j]=false;
    }
    for(long long i=1,j;i<=n;i=j+1)
        j=n/(n/i),v[++cnt]=n/j;
    For(i,1,cnt) f[i]=v[i]-1;
    For(k,1,pr[0]) For(i,1,cnt)
        if(1ll*pr[k]*pr[k] > v[i]) break;
        else f[i]-=f[get(v[i]/pr[k])]-(k-1);
    For(i,1,pr[0]) ans+=f[get(n/pr[i])]-i;
    printf("%lld\n",ans+f[get(m)]);
    return 0;
}
