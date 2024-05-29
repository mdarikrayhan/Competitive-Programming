#include<cstdio>
int n,d,x,y,v,r,i;int main(){scanf("%d%d",&n,&d);for(i=2*n-2;i>=0;i-=2){r=4*v|(d>>i)&3;x=(x<<1)|(0x936c>>r)&1;y=(y<<1)|(0x39c6>>r)&1;v=(0x3e6b94c1>>2*r)&3;}printf("%d %d",x,y);}