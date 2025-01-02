#include <cmath>
#include <cstdio>
int N,R;
double ans,s;
int main()
{
	scanf("%d%d",&N,&R),ans=N+(N-1)*(sqrt(2)+2);
	for (int i=3; i<=N; i++) s+=(2*sqrt(2)+i-1)*(i-2);
	printf("%.10lf\n",(ans+s)*2*R/N/N);
	return 0;
}