#include<bits/stdc++.h>
using namespace std;
int a[255];
int main(){
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s=0;
		for(int i=0;i<250;++i)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		double ave=s/250.0;
		int cnt=0;
		for(int i=0;i<250;++i)
		{
			if(fabs(a[i]-ave)<=ave/2)
				++cnt;
		}
		if(cnt>250*0.75)
			puts("poisson");
		else
			puts("uniform");
	}
	return 0;
}