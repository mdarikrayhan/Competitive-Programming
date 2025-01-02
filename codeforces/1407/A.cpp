#include<iostream>
int t,n,s,i,d,b;main()
{
    for(scanf("%d",&t);t--;puts(""))
    {
        for(scanf("%d",&n),i=s=0;i++<n;s+=d)scanf("%d",&d);
        for(printf("%d\n",b=std::max(s-s%2,n-s)),i=0;i++<b;)printf("%d ",s>n/2);
    }
}