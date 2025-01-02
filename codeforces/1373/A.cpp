#include<stdio.h>
int main()
{
    int t,a,b,c;
    for(scanf("%d",&t);t--&&scanf("%d%d%d",&a,&b,&c);printf("%d %d\n",a>=c?-1:1,a<=c/b?-1:b));
}