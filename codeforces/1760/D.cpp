#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int n,a1,a,s=0;
	cin>>n>>a1;
	for(int i=1;i<n;i++)
{
	cin>>a;
	if(a1<a)s=max(s,1);
	if(a1>a && s)s=2;
	a1=a;
}
	if(s<=1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
	
}