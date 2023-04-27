#include<iostream>
using namespace std;
int main()
{
int t;cin>>t;
while(t--)	
{
	long long n,x,i,j=1,s=0;
	cin>>n>>x;
	long long a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;a[i]%j==0;i=i%n)
	{   
	    s=s+a[i];
		if(i+1==n) j=j*x;
		i++;
	}
    cout<<s<<endl;
}
}