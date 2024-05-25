#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int H,M;
	cin>>H>>M;
	int h,d,c,n;
	cin>>h>>d>>c>>n;
	double mon1,mon2;
	int time=0;
	if(H<20)
	{
		time+=(19-H)*60+60-M;
		if((h+time*d)%n==0)
		{
			mon1=0.8*c*(h+time*d)/n;	
		}
		else
		{
			mon1=0.8*c*((h+time*d)/n+1);	
		}
		if(h%n==0)
		{
			mon2=c*(h/n);	
		}	
		else
		{
			mon2=c*(h/n+1);
		}
		cout<<fixed<<setprecision(4)<<min(mon1,mon2);
	}	
	else
	{
		if(h%n==0)
		{
			cout<<fixed<<setprecision(4)<<0.8*c*(h/n);
		}
		else
		{
			cout<<fixed<<setprecision(4)<<0.8*c*(h/n+1);
		}
	}
	return 0;
} 
 	   	 	       			  	   	 	