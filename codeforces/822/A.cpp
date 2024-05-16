#include<stdio.h>
int main()
{
    int a,b,j,result=1;
    scanf("%d%d",&a,&b);
    if(a>b)
    {
        for(j=1;j<=b;j++)
        {
            result=result*j;
        }
    }
    else
    {
       for(j=1;j<=a;j++)
       {
           result=result*j;
       }
    }
    printf("%d",result);
}
