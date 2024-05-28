#include<cstdio>
int f,s,t,n,m;
void g(){
int _t=(s>f? s-f:f-s);
int x=t%(2*(m-1));
if(s>f)s=((2*(m-1))-s)%(2*(m-1));
int t2=t+(s-x+2*(m-1))%(2*(m-1));
if(s==f)t2=t;
printf("%d\n",t2+_t);
}
int main(){
scanf("%d%d",&n,&m);
for(int i=0;i<n;i++)
scanf("%d%d%d",&s,&f,&t),s--,f--,g();
}
