// LUOGU_RID: 160136334
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e3+1,C=26;
void kmpSelf(string& s,int* arr)
{
	for(int i=1,j=0;i<s.length();i++)
	{
		for(;j && s[i]!=s[j];j=arr[j-1]);
		j+=(s[i]==s[j]);
		arr[i]=j;
	}
	return;
}
string s,t,ans;
int n,k,arr[N];
void work()
{
	cin>>n>>k>>s>>t;
	ans.resize(n,0);
	kmpSelf(s,arr);
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='0')
		{
			continue;
		}
		for(int j=0;j<s.length();j++)
		{
			int p=i+j;
			if(ans[p] && ans[p]!=s[j])
			{
				printf("No solution");
				return;
			}
			ans[p]=s[j];
		}
	}
	for(int i=0,j=0;i<n;i++)
	{
		if(!ans[i])
		{
			ans[i]='a'+(s[j]=='a');
		}
		for(;j && ans[i]!=s[j];j=arr[j-1]);
		j+=(ans[i]==s[j]);
		if(j==s.length())
		{
			if(t[i-s.length()+1]=='0')
			{
				printf("No solution");
				return;
			}
			j=arr[j-1];
		}
	}
	cout<<ans;
	return;
}
int main()
{
//	freopen("data.txt","r",stdin);
	work();
	return 0;
}