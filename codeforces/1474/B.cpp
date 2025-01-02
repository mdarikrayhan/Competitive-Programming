#include<iostream>
int d,i,j,t,x,y,a[20160];
main()
{
	for(i=1;i++<144;)if(!a[i])for(j=i*i;j<20160;j+=i)a[j]=1;
std::cin>>t;
	while(t--)
	{
		std::cin>>d;
		for(x=d+1;a[x];)x++;
		for(y=x+d;a[y];)y++;
		std::cout<<x*y<<"\n";
	}
}