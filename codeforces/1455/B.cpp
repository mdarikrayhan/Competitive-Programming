#include<cstdio>
int main(){ int t,n,c=0,s=0;for(scanf("%d",&t);t--;printf("%d\n",c+(s==n+1)),c=s=0) for(scanf("%d",&n);s<n;) s+=++c;}