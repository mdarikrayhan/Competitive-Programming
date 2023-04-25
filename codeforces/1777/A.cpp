#include<stdio.h>
int main(){int t;for(scanf("%d",&t);t--;){int n,x=-1,y,cnt=0;for(scanf("%d",&n);n--;x=y)scanf("%d",&y),y&=1,cnt+=(x==y);printf("%d\n",cnt);}}