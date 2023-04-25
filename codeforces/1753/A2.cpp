#include<cstdio>
using namespace std;
const int N=2e5+2;
int T,n,s,k,a[N],l[N],r[N];bool b[N];
int main(){
scanf("%d",&T);
while(T--){
scanf("%d",&n),s=0;
for(int i=1;i<=n;++i)
scanf("%d",a+i),s+=a[i],b[i]=0;
if(s&1){printf("-1\n");continue;}
s>>=1,l[1]=r[1]=k=1;
for(int i=2;i<=n;++i)
if(a[i]*s>0&&!b[i-1]) s-=a[i],b[i]=1,r[k]=i;
else ++k,l[k]=r[k]=i;
printf("%d\n",k);
for(int i=1;i<=k;++i)
printf("%d %d\n",l[i],r[i]);
}
return 0;
}