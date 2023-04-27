#include <iostream>
using namespace std;

int main()
{
	int t,a,b,c,d;
	cin>>t;
	while(t--)
	{
		bool ar[4]={0};
		cin>>a>>b>>c>>d;
		ar[((a+b)%2)*2]=true;
		ar[((a+b)%2)*2+1]=true;
		if(b+c==0) ar[1]=true,ar[2]=true;
		if(a+d==0) ar[0]=true,ar[3]=true;
		for(int i=0;i<4;i++) 
		{
			if(ar[i]) cout<<"Tidak"<<" ";
			else cout<<"Ya"<<" ";
		}
		cout<<"\n";
	}
}