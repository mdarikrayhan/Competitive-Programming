#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,m,a[N],b[N],p[N],arr[N];
void add(int x){for(;x<=m;x+=x&-x)arr[x]++;}
int sum(int x,int y=0){for(;x;x-=x&-x)y+=arr[x];return y;}

int main(){
scanf("%d",&n);
for(int i=1;i<=n;++i){
scanf("%d%d",a+i,b+i);
p[a[i]]=b[i];
p[b[i]]=a[i];
}
m=n*2;
long long T1=0,T2=0;
for(int i=1;i<=m;++i){
if(i<p[i])continue;
int x=sum(i)-sum(p[i]-1);
int z=i-p[i]-1-x-x;
int y=n-1-x-z;
T1+=1LL*x*y;
T2+=1LL*(x+y)*z;
add(p[i]);
}
cout<<1LL*n*(n-1)*(n-2)/6-T1-T2/2<<endl;
return 0;
}