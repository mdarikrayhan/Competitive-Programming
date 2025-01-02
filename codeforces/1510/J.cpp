// LUOGU_RID: 156793902
#include <bits/stdc++.h>
using namespace std;
string s;
int c[100000];
vector<int>ansv;
void prtans(int n){
	int i,cur=0;
	for(i=0;i<n;i++)
	{
		if(c[i])cur++;
		else
		{
			if(cur>0)ansv.push_back(cur);
			cur=0;
		}
	}
	if(cur>0)ansv.push_back(cur);
	cout<<ansv.size()<<'\n';
	for(i=0;i<ansv.size();i++)cout<<ansv[i]<<' ';
	cout<<'\n';
}
bool check(int d){
	int n=s.length(),i,j;
	for(i=0;i<n&&i<d;i++)
	{
		if(s[i]=='#'||s[n-i-1]=='#')return 0;
	}
	for(i=0;i<n;i++)
	{
		if(s[i]=='#')c[i]=1;
		else c[i]=0;
	}
	for(i=0;i<n-d;i++)
	{
		if(c[i]&&(i==0||c[i-1]==0))
		{
			if(i-d-1>=0&&c[i-d-1]==1)return 0;
			for(j=1;j<=d;j++)
			{
				if(c[i-j]==1)return 0;
				c[i-j]=1;
			}
		}
	}
	if(d==0)
	{
		for(i=0;i<n-d-1;i++)
		{
			if(c[i]==0&&c[i+1]==0)return 0;
		}
		if(c[0]==0||c[n-d-1]==0)return 0;
		prtans(n);
		return 1;
	}
	if(d==1)
	{
		for(i=0;i<n-d;i++)
		{
			if((i==0||c[i-1]==0)&&c[i]==0&&(i==n-d-1||c[i+1]==0))c[i]=1;
		}
		for(i=0;i<n-d-1;i++)
		{
			if(c[i]==0&&c[i+1]==0)return 0;
		}
		if(c[0]==0||c[n-d-1]==0)return 0;
		prtans(n);
		return 1;
	}
	for(i=0;i<n-d;i++)
	{
		if((i==0||c[i-1]==0)&&c[i]==0&&(i==n-d-1||c[i+1]==0))
		{
			c[i]=1;
			if(i+2==n-d||(i+3<n-d&&c[i+2]==0&&c[i+3]==1))c[i+1]=1;
		}
	}
	for(i=0;i<n-d-1;i++)
	{
		if(c[i]==0&&c[i+1]==0)return 0;
	}
	if(c[0]==0||c[n-d-1]==0)return 0;
	prtans(n);
	return 1;
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int i,flag;
	cin>>s;
	flag=0;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='#')flag=1;
	}
	if(!flag)
	{
		cout<<"0\n";
		cout<<'\n';
		return 0;
	}
	flag=0;
	for(i=0;i<6;i++)
	{
		if(check(i))
		{
			flag=1;
			break;
		}
	}
	if(!flag)cout<<"-1\n";
	return 0;
}