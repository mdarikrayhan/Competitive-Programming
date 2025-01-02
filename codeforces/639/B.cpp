#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,h;
    scanf("%d%d%d",&n,&d,&h);
    if(d>2*h||(d==1&&h==1&&n>=3))
    {
        printf("-1");
        return 0;
    }
    for(int i=2;i<=h+1;i++)
    {
        printf("%d %d\n",i-1,i);
    }
    if(d>h)
    {
        printf("1 %d\n",h+2);
        for(int i=h+3;i<=d+1;i++)
        {
            printf("%d %d\n",i-1,i);
        }
    }
    for(int i=d+2;i<=n;i++)
    {
        printf("%d %d\n",1+(int)(d==h),i);
    }
    return 0;
}
  				 				 	    	  	 			     	