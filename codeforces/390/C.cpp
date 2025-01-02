#include<cstdio>
int n,k,w,l,r;
int a[100001],c[100001];
char s[100001];
int main(){
scanf("%d%d%d%s",&n,&k,&w,s+1);
for(int i=1;i<=k;i++)c[i]=s[i]-'0',a[i]=a[i-1]+s[i]-'0';
for(int i=k+1;i<=n;i++)a[i]=a[i-1]+s[i]-'0',c[i]=c[i-k]+s[i]-'0';
while(w--){
scanf("%d%d",&l,&r);
printf("%d\n",a[r]-a[l-1]-c[r]+c[l-1]+(r-l+1)/k-c[r]+c[l-1]);
}
}