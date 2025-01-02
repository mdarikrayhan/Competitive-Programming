#include<bits/stdc++.h>
using namespace std;
bool calcwin(long long a,long long b){
	int tag=0;
	long long bx=b;
	while(1)
	{
		if(a>b/2)
		{
			if(tag==0)
			{
				if(a%2==bx%2)return 0;
				return 1;
			}
			return 1;
		}
		if(tag==1)
		{
			bx=b/2;
			tag=0;
		}
		else if(bx%2==0)tag=1;
		b/=2;
	}
	return -1;
}
bool calclose(long long a,long long b){
	if(a>b/2)return 0;
	return calcwin(a,b/2)^1;
}
long long a[100000],b[100000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,c;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i]>>b[i];
	c=1;
	for(i=n-1;i>-1;i--)
	{
		if(c==1)c=calcwin(a[i],b[i])^1;
		else c=calclose(a[i],b[i]);
	}
	if(c==0)cout<<"1 ";
	else cout<<"0 ";
	c=0;
	for(i=n-1;i>-1;i--)
	{
		if(c==1)c=calcwin(a[i],b[i])^1;
		else c=calclose(a[i],b[i]);
	}
	if(c==0)cout<<"1\n";
	else cout<<"0\n";
	return 0;
}