#include <bits/stdc++.h>
using namespace std;
long long a[200000],b[200000];
vector<long long>vec,ansv;
void solve1(long long n){
	long long i,j,csum;
	int tag=-1;
	while(1)
	{
		if(b[0]==0||b[1]==0)
		{
			cout<<"IMPOSSIBLE\n";
			return;
		}
		if(b[0]==a[0])
		{
			if(b[1]%b[0]==a[1]%b[0]&&b[1]>=a[1])
			{
				vec.push_back((b[1]-a[1])/b[0]);
				tag=0;
				break;
			}
		}
		if(b[1]==a[1])
		{
			if(b[0]%b[1]==a[0]%b[1]&&b[0]>=a[0])
			{
				vec.push_back((b[0]-a[0])/b[1]);
				tag=1;
				break;
			}
		}
		swap(a[0],a[1]);
		if(b[0]==a[0])
		{
			if(b[1]%b[0]==a[1]%b[0]&&b[1]>=a[1])
			{
				vec.push_back((b[1]-a[1])/b[0]);
				ansv.push_back(0);
				tag=0;
				break;
			}
		}
		if(b[1]==a[1])
		{
			if(b[0]%b[1]==a[0]%b[1]&&b[0]>=a[0])
			{
				vec.push_back((b[0]-a[0])/b[1]);
				ansv.push_back(0);
				tag=1;
				break;
			}
		}
		swap(a[0],a[1]);
		if(b[0]>=b[1])
		{
			vec.push_back(b[0]/b[1]);
			b[0]%=b[1];
		}
		else
		{
			vec.push_back(b[1]/b[0]);
			b[1]%=b[0];
		}
	}
	csum=0;
	for(i=0;i<vec.size();i++)csum+=vec[i];
	if(csum<=200000)
	{
		cout<<"SMALL\n";
		for(i=(int)vec.size()-1;i>-1;i--)
		{
			if(tag)ansv.push_back(0);
			for(j=0;j<vec[i];j++)ansv.push_back(1);
			if(tag)ansv.push_back(0);
			tag^=1;
		}
		cout<<ansv.size()<<'\n';
		for(i=0;i<ansv.size();i++)
		{
			if(ansv[i])cout<<'P';
			else cout<<'R';
		}
		cout<<'\n';
	}
	else
	{
		cout<<"BIG\n";
		cout<<csum<<'\n';
	}
}
void solve2(long long n){
	long long i,ansc;
	int flag;
	while(1)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(b[i]!=a[i])flag=1;
		}
		if(!flag)break;
		flag=0;
		for(i=0;i<n;i++)
		{
			if(b[i]!=a[n-i-1])flag=1;
		}
		if(!flag)
		{
			ansv.push_back(0);
			break;
		}
		flag=0;
		for(i=0;i<n-1;i++)
		{
			if(b[i+1]<=b[i])flag=1;
		}
		if(!flag)
		{
			for(i=n-1;i>0;i--)b[i]-=b[i-1];
			ansv.push_back(1);
			continue;
		}
		flag=0;
		for(i=0;i<n-1;i++)
		{
			if(b[i+1]>=b[i])flag=1;
		}
		if(!flag)
		{
			reverse(b,b+n);
			for(i=n-1;i>0;i--)b[i]-=b[i-1];
			ansv.push_back(0);
			ansv.push_back(1);
			continue;
		}
		cout<<"IMPOSSIBLE\n";
		return;
	}
	ansc=0;
	for(i=0;i<ansv.size();i++)
	{
		if(ansv[i]==1)ansc++;
	}
	if(ansc<=200000)
	{
		cout<<"SMALL\n";
		cout<<ansv.size()<<'\n';
		for(i=(int)ansv.size()-1;i>-1;i--)
		{
			if(ansv[i])cout<<'P';
			else cout<<'R';
		}
		cout<<'\n';
	}
	else
	{
		cout<<"BIG\n";
		cout<<ansc<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)cin>>b[i];
	if(n==1)
	{
		if(a[0]==b[0])
		{
			cout<<"SMALL\n";
			cout<<"0\n";
			cout<<'\n';
		}
		else cout<<"IMPOSSIBLE\n";
		return 0;
	}
	if(n==2)solve1(n);
	else solve2(n);
	return 0;
}