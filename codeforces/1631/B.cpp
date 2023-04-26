#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],l,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		l=n,A=00;
		while(l>1)
			if(a[l-1]==a[n])
				l--;
			else
				l-=n-l+1,A++;
		cout<<A<<'\n';
}}