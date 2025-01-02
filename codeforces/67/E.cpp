#include<cstdio>
using namespace std;
int n,i,t,ee,flag;
long long x[1010],y[1010];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%I64d%I64d",&x[i],&y[i]);t=n;
    if(y[n]>y[1])for(i=1;i<=n;i++)y[i]=-y[i],x[i]=-x[i];
    for(i=x[1];i<=x[2]&&t>2;i++)
        for(;(x[t]-i)*(y[t-1]-y[1])-(x[t-1]-i)*(y[t]-y[1])>=0&&t>2;t--);ee=i-1;t=2;
    for(i=x[2];i>=x[1]&&t<n;i--)
        for(;(x[t]-i)*(y[t+1]-y[1])-(x[t+1]-i)*(y[t]-y[1])<=0&&t<n;t++);i++;
    if(i-ee+1>0)printf("%d\n",i-ee+1);else printf("0\n");   
}