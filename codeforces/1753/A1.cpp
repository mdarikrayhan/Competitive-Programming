#include<cstdio>
using namespace std;
int n,T,a[200001],p[200001],cnt;
int main(){
scanf("%d",&T);
while(T--){
scanf("%d",&n);
int _=0;cnt=0;
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
if(n&1||i&1)continue;
if(a[i]==a[i-1])p[++cnt]=i;
else p[++cnt]=i-1,p[++cnt]=i;
}
if(n&1)printf("-1\n");
else printf("%d\n",cnt);
for(int i=1;i<=cnt;i++)printf("%d %d\n",p[i-1]+1,p[i]);
}
return 0;
}