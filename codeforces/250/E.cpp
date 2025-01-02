#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,x,y,now,d,w[2],a[110][10032];
long long ans=0;
int main(){
scanf("%d%d",&n,&m);
for(int i=0;i<n;i++)
for(int j=0;j<m;j++){
if(j==0)getchar();
switch(getchar()){
case '.':break;
case '+':a[i][j]=1;break;
case '#':a[i][j]=2;break;
}
}
d=1,now=0;
x=y=w[0]=w[1]=0;
for(int T=10000000;T;T--){
if(x==n-1){printf("%I64d\n",ans);return 0;}
if(!a[x+1][y])x++,w[0]=w[1]=y;else 
if(y==w[now])
if((y+d>=0)&&(y+d<m)&&(a[x][y+d]<2)){
w[now]+=d;
if(!a[x][y+d])y+=d;
else now^=1,d*=-1;
}
else now^=1,d*=-1;
else{
ans+=(long long)abs(w[now]-y)-1;
y=w[now];
}
ans++;
}
printf("Never\n");
scanf("%d",&n);
return 0;
}