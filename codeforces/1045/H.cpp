#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define P 1000000007
#define ll long long
int fac[N],ifa[N],a,b,c,d,g,len,ans;char A[N],B[N];
ll ksm(ll a,ll b){ll g=1;for(;b;b>>=1,a=a*a%P) if(b&1) g=g*a%P;return g;}
ll C(int n,int m){if(n<m||n<0||m<0) return 0;return 1ll*fac[n]*ifa[m]%P*ifa[n-m]%P;}
ll f(int n,int m){if(m==0) return n==0;return C(n+m-1,m-1);}
int gao(char *s)
{
    if(s[0]=='0') return 0;
    int res=1ll*f(a,c)*f(d,b)%P,len=strlen(s);
    if(len>a+b+c+d) return res;if(len<a+b+c+d) return 0;
    int na=a,nd=d,nc=c,nb=b;
    for(int i=1;i<len;i++)
	{
		s[i-1]=='1'?nd--:nc--;if(s[i]=='1')continue;
		res=(res-(ll)f(na,nc)*f(nd,nb)%P+P)%P;
		s[i-1]=='1'?nd++:nc++;s[i-1]=='1'?nb--:na--;
	}
	return res;
}
int main()
{
    fac[0]=1;for(int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%P;
    ifa[N-1]=ksm(fac[N-1],P-2);for(int i=N-2;~i;i--) ifa[i]=1ll*ifa[i+1]*(i+1)%P;
    scanf("%s%s",A,B);scanf("%d%d%d%d",&a,&b,&c,&d);b++;
    if(c>b||c<b-1) puts("0"),exit(0);len=strlen(A);g=len-1;
    while(A[g]=='0') g--;A[g]='0';for(int i=g+1;i<len;i++) A[i]='1';
    if(!g&&len>1) for(int i=0;i<len;i++) A[i]=A[i+1];
    ans=(gao(B)-gao(A)+P)%P;printf("%d\n",ans);
}