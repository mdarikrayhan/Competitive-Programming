#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1111],l[11],r[11];
void dfs(int t){
 bool ok=1;for(int i=1;ok&&i<=n;++i)if(a[i]!=i)ok=0;
 if(ok){printf("%d\n",t-1);for(int i=t-1;i;i--)printf("%d %d\n",l[i],r[i]);exit(0);}
 if(t>3)return;
 for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(abs(a[i-1]-a[j])==1||abs(a[i]-a[j+1])==1)
  l[t]=i,r[t]=j,reverse(a+i,a+j+1),dfs(t+1),reverse(a+i,a+j+1);}
int main(){
 scanf("%d",&n);
 for(int i=1;i<=n;++i)scanf("%d",&a[i]);
 a[0]=0,a[n+1]=n+1,dfs(1);
 return 0;
}