// LUOGU_RID: 155627874
#include<bits/stdc++.h>
using namespace std;
map<string,int> h;
int type(string &s,int l,int r)
{
	int pos=0,brac=0;
	for (int i=r;i>=l;i--)
	{
		if (s[i]=='(') brac++;
		else if (s[i]==')') brac--;
		if (brac==0&&(s[i]=='+'||s[i]=='-'))
		{
			int st1=type(s,l,i-1),st2=type(s,i+1,r);
			if (st1==1||st2==1) return 1;
			if (s[i]=='+') return 2;
			if (s[i]=='-')
			{
				if (st2==2) return 1;
				else return 2;
			}
		}
		if (brac==0&&pos==0&&(s[i]=='*'||s[i]=='/')) pos=i;
	}
	if (pos!=0)
	{
		int st1=type(s,l,pos-1),st2=type(s,pos+1,r);
		if (st1==1||st2==1) return 1;
		if (s[pos]=='*')
		{
			if (st1==2||st2==2) return 1;
			else return 3;
		}
		if (s[pos]=='/')
		{
			if (st1==2||st2==2||st2==3) return 1;
			return 3;
		}
	}
	else if (s[l]=='('&&s[r]==')')
	{
		if (type(s,l+1,r-1)==1) return 1;
		return 0;
	}
	else
	{
		if (h.find(s.substr(l,r-l+1))!=h.end()) return h[s.substr(l,r-l+1)];
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s,a,b="";
		cin>>s;
		if (s=="#") cin>>s;
		cin>>s;
		getline(cin,a);
		for (int i=0;i<a.size();i++)
			if (a[i]!=' ') b+=a[i];
		h[s]=type(b,0,b.size()-1);
	}
	string x,s="";
	getline(cin,x);
	for (int i=0;i<x.size();i++)
		if (x[i]!=' ') s+=x[i];
	if (type(s,0,s.size()-1)==1) cout<<"Suspicious";
	else cout<<"OK";
	return 0;
}