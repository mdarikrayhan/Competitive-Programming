#include<bits/stdc++.h>
const int MAX=200005;
long long n,t,a[MAX],x[MAX],b[MAX],i;
int main()
{
      scanf("%lld%lld",&n,&t);
      for(i=1;i<=n;i++)scanf("%lld",&a[i]);for(i=1;i<=n;i++)scanf("%lld",&x[i]);for(i=1;i<=n;i++){if(x[i]<x[i-1]||x[i]<i){printf("No");return 0;}}b[n]=a[n]+t+1000000;for(i=n-1;i>=1;i--)b[i]=a[i+1]+t-(i==x[i]);for(i=1;i<n;i++){if((x[i]<x[i+1]&&x[i]!=i)||b[i]==b[i+1]){printf("No");return 0;}}printf("Yes\n");for(i=1;i<=n;i++)printf("%lld ",b[i]);return 0;}