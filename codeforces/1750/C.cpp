#include<cstdio>
using namespace std;
const int N=2e5+2;
int T,n,s,x;char a[N],b[N];main(){scanf("%d",&T);while(T--){scanf("%d %s %s",&n,a+1,b+1);s=x=0;for(int i=1;i<=n;++i) s+=a[i]^b[i],x+=a[i]&1;if(s&&s<n){printf("NO\n");continue;}printf("YES\n");if(x%2^!s) printf("%d\n",x);else printf("%d\n1 1\n1 %d\n2 %d\n",x+3,n,n);for(int i=1;i<=n;++i) if(a[i]&1)printf("%d %d\n",i,i);}}