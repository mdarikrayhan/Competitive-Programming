#include<stdio.h>
#include<math.h>
int main()
{
	int n,R,r;
	double a;
	scanf("%d%d%d",&n,&R,&r);
	if(r>R)
	{
		printf("NO\n"); 
	}
	else if(2*r>R)
	{
		if(n==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
			a=asin((double)r/(R-r));
			if(acos(-1)-a*n>-1e-10)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
	}
	return 0;
}
