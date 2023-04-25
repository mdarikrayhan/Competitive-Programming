#include<cstdio>
using namespace std;
int p=1000000007;
int main(){int t,n;scanf("%d",&t);while(t--){scanf("%d",&n);int x=1;for(int i=2;i<=n;i++)x=1ll*x*i%p;printf("%d\n",1ll*x*n%p*(n-1)%p);}}