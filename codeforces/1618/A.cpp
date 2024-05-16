#include<stdio.h>
int main()
{
    long long t,i,j,a,b,c,d,e,f,g;
    scanf("%lld",&t);
   for(i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
        if(a+b+c==g)
        {
            printf("%lld %lld %lld\n",a,b,c);
        }
        else if(a+b+d==g)
        {
            printf("%lld %lld %lld\n",a,b,d);
        }
        else if(a+b+e==g)
        {
            printf("%lld %lld %lld\n",a,b,e);
        }
        else if(a+c+d==g)
        {
            printf("%lld %lld %lld\n",a,c,d);
        }
        else
        {
            printf("%lld %lld %lld\n",a,c,e);
        }
    }
}
