// LUOGU_RID: 159180979
#include<bits/stdc++.h>
using namespace std;
int n;
int a[314514];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	  
	sort(a+1,a+1+n);
	n=ceil(n/2.0);
	cout<<a[n];  
	
	
	
	return 0;
 } 