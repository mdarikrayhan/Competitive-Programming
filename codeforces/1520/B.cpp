#include <iostream>
using namespace std;
int main() 
{
  int t,i,c;
  long long int n,s;
	cin>>t;
    while(t--)
	{
    	 c=0;
    	cin>>n;
    	for(i=1;i<=9;i++)
    	{
    		s=i;
    		while(s<=n)
    		{
    			c++;
    			s=s*10+i;
			}
		}
		cout<<c<<endl;
    }

    return 0;
}