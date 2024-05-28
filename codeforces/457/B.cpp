#include<bits/stdc++.h>
#define ll long long
#define rep(i,c,d) for(int i=c;i<=d;i++)
using namespace std;
const int maxn=100010;
ll a[maxn],b[maxn],sum1,sum2,ans1,ans2;
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    rep(i,1,N) scanf("%lld",&a[i]),sum1+=a[i];
    rep(i,1,M) scanf("%lld",&b[i]),sum2+=b[i];
    ans1=sum2; ans2=sum1;
    sort(a+1,a+N+1); sort(b+1,b+M+1);
    rep(i,1,N-1) ans1+=min(a[i],sum2);
    rep(i,1,M-1) ans2+=min(b[i],sum1);
    printf("%lld\n",min(ans1,ans2));
    return 0;
}
